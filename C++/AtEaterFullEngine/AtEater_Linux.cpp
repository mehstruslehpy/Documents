///TODO: fix the monster teleporting glitch
///      prevent the monsters from eating each other
#include <iostream>
#include <stdlib.h>
#include <ctime>
///needed for Sleep possibly
///conio is not portable you should use pdcurses/ncurses instead
///#include <conio.h>
///need vectors because I'm lazy
#include <vector>
#include <fstream>
#include <string>
///#include <windows.h>
///#include <curses.h>
///stuff for keyboard input
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <sys/ioctl.h>
using namespace std;

//globals for convenience
int ROWS = 0;
int COLS = 0;
int difficulty = 99999;
///globals for current position on board
int playerRow = 0;
int playerCol = 0;
///function prototypes
//to display the board
void dispBoard(vector<vector<char>>);
///clear the previous board..
void ClearScreen();
///move every monster on the board
int moveMonsters(vector<vector<char>>&);
///move a single monster on the board
int moveMonster(vector<vector<char>>&, int, int, int, int&);

///initialize the board with a board vector and a filename
void initBoard(vector<vector<char>>&, string);
///move the player
int moveSpot(vector<vector<char>>&);

///an input wrapper
char getinput();
int getch(void);
int kbhit(void);
void changemode(int);
//check for a win
int checkBoard(vector<vector<char>>&);

int main(int argc, char *argv[])
{
    ///setup the game...
    ///seed random number generator
    srand(time(0));
    int endFlag = 0;
    ///the game board to use will be stored in this vector
    vector<vector<char>> board;
    string mapName;
    ///find out which map file to load
    if (argc==3)
    {
        ///if they specified a map via standard input
        initBoard(board, argv[1]);
		difficulty = stoi(argv[2],NULL);
		switch (difficulty)
		{
			case 1:
				difficulty = 90000;
				break;
			case 2:
				difficulty = 100000;
				break;
			case 3:
				difficulty = 120000;
				break;
			case 4:
				difficulty = 159000;
				break;
			case 5:
				difficulty = 162000;
				break;
			default:
				difficulty = 159000;
				break;	
		}

    }
    else
    {
        cout << "Please specify a map to load: " << endl;
        getline(cin, mapName);
        initBoard(board, mapName);
        cout << "Please specify a difficulty level[1-5]: " << endl;
        getline(cin, mapName);
		difficulty = stoi(mapName.c_str(),NULL);
			switch (difficulty)
		{
			case 1:
				difficulty = 90000;
				break;
			case 2:
				difficulty = 100000;
				break;
			case 3:
				difficulty = 120000;
				break;
			case 4:
				difficulty = 159000;
				break;
			case 5:
				difficulty = 162000;
				break;
			default:
				difficulty = 159000;
				break;	
		}
    }
    ///the game loop
    do
    {
        dispBoard(board);
        endFlag = moveSpot(board);
        if (endFlag == -1)
            return 0;
        endFlag = moveMonsters(board);
        if (endFlag == -1)
            return 0;
        //check for a win
        endFlag = checkBoard(board);
    }
    while (endFlag == 0);
    ///endwin();
    return 0;
}

int moveSpot(vector<vector<char>>& arr)
{
    ///return 0 for normal -1 for lose
    int returnState = 0;
    int prevRow = playerRow;
    int prevCol = playerCol;
    bool goodInput = false; ///determine if an input is valid
    arr[playerRow][playerCol] = ' ';
    char choice = 'N';

    ///read and validate an input do not allow a player to read beyond the edge of the board
    do
    {

        ///reset any moves that touch pound signs(walls)
        if(arr[playerRow][playerCol] == '#')
        {
            playerRow = prevRow;
            playerCol = prevCol;
            goodInput=false;
        }

        do
        {
            choice = getinput();
            ///these can be used to change game-refresh rate
            goodInput = true;
            usleep(difficulty);
            if (choice == 's' && playerRow == (ROWS - 1))
            {
                goodInput = false;
            }
            else if (choice == 's' && playerRow != (ROWS - 1))  ///check if we are exceeding the array bounds
            {
                playerRow++;
                goodInput = true;
            }
            else if (choice == 'w' && playerRow == 0)
            {
                goodInput == false;
            }
            else if (choice == 'w' && playerRow != 0)
            {
                playerRow--;
                goodInput = true;
            }
            else if (choice == 'a' && playerCol == 0)
            {
                goodInput == false;
            }
            else if (choice == 'a' && playerCol != 0)
            {
                playerCol--;
                goodInput = true;
            }
            else if (choice == 'd' && playerCol == (COLS-1))
            {
                goodInput == false;
            }
            else if (choice == 'd' && playerCol != (COLS-1))
            {
                playerCol++;
                goodInput = true;
            }
        }
        while (goodInput == false);
        ///exit the game if the player hits an M (for monster!)
        if(arr[playerRow][playerCol] == 'M')
        {
            ClearScreen();
            cout << "OOPS YOU'RE DEAD!" << endl;
            return -1;
        }
    }
    while(arr[playerRow][playerCol] == '#');
    arr[playerRow][playerCol] = '0';
    return returnState;
}

void dispBoard(vector<vector<char>> arr)
{
    ///for some reason refreshboard() is fairly seizure inducing..
    ///system("cls") causes flickering depending on the refresh rate of the game
    ///system("cls");
    ClearScreen();
    ///refreshBoard();

    ///draw the board
    cout << "Eat the @'s, but don't get eaten by any monsters! (use w,a,s,d to move)" << endl;
    for (int i = 0; i < ROWS; i++)
    {
        for (int n = 0; n < COLS; n++)
        {

            cout << arr[i][n] << " ";
        }
        cout << endl;
    }
}

int checkBoard(vector<vector<char>>& arr)
{
    for(int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (arr[i][j] == '@')
                return 0;
        }
    }
    ClearScreen();
    cout << "GOOD JOB, YOU WON!" << endl;
    return 1;
}

///there is a bug in which monsters seem to teleport in this program
///I could not figure out why this was for quite a while until I considered a special case:
///
///imagine the array iterating from left to right bottom to top, you move a single monster down by a single row
///that monster gets its move and you continue until you encounter that monster yet again later
///so you move it again giving it a second move
///I do not know a convenient way to handle this yet...
int moveMonsters(vector<vector<char>>& arr)
{
    int eatenFlag = 0;
    ///0 = up 1 = down 2 = left 3 = right
    int direction = -1;
    int retry = 0;
    int monsterCount = 0;
    ///vectors for monster coordinates
    vector<int> monsterRow;
    vector<int> monsterCol;
    ///count up the monsters and gather their coordinates
    for(int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            ///retry = 0;
            direction = rand() % 4;
            if (arr[i][j] == 'M')
            {
                monsterRow.push_back(i);
                monsterCol.push_back(j);
                monsterCount++;
            }
        }
    }
    ///move each monster
    for (int i = 0; i < monsterCount; i++)
    {

        do
        {
            ///retry = 0;
            direction = rand() % 4;
            retry = moveMonster(arr, monsterRow[i],monsterCol[i], direction, eatenFlag);

        }
        while (retry == -1);
    }

    if(eatenFlag == -1)
    {
        ClearScreen();
        cout << "OM NOM YOU GOT EATEN!" << endl;

    }
    return eatenFlag;
}

int moveMonster(vector<vector<char>>& arr, int row, int col, int direction, int &eatenflag)
{
    if (direction == -1)
    {
        return -1;
    }

    switch (direction)
    {
    case 0:
        if (row-1 < 0)
            return -1;
        if (arr[row-1][col] == '#'|| arr[row-1][col] == '@'||arr[row-1][col] == 'M')
            return -1;
        if(arr[row-1][col] == '0')
            eatenflag = -1;
        arr[row][col] = ' ';
        row=row-1;
        arr[row][col] = 'M';
        return 0;
    case 1:
        if (row > ROWS)
            return -1;
        if (arr[row+1][col]=='#'||arr[row+1][col]=='@'||arr[row+1][col] == 'M')
            return -1;
        if(arr[row+1][col] == '0')
            eatenflag = -1;
        arr[row][col] = ' ';
        row=row+1;;
        arr[row][col] = 'M';
        return 0;
    case 2:
        if (col-1 < 0)
            return -1;
        if (arr[row][col-1] == '#'|| arr[row][col-1] == '@'||arr[row][col-1] == 'M')
            return -1;
        if(arr[row][col-1] == '0')
            eatenflag = -1;
        arr[row][col] = ' ';
        col=col-1;
        arr[row][col] = 'M';
        return 0;
    case 3:
        if (col > COLS)
            return -1;
        if (arr[row][col+1]=='#'||arr[row][col+1]=='@'||arr[row][col+1] == 'M')
            return -1;
        if(arr[row][col+1] == '0')
            eatenflag = -1;
        arr[row][col] = ' ';
        col=col+1;
        arr[row][col] = 'M';
        return 0;
    default:
        return -1;

    }
    return -1;

}

///this was rewritten by me based on the windows version and the new functions
char getinput()
{
	changemode(1);
	char c = 0;
	if (kbhit())
	{
		c = getch();
	}
		changemode(0);
		return c;
}

void ClearScreen()
{
	system("clear");
}

///inspiration for this comes from here:
///https://stackoverflow.com/questions/33108785/reading-characters-from-a-file-one-at-a-time-c-and-storing-to-a-2d-array
///https://stackoverflow.com/questions/30445200/passing-vector-of-vectors-to-function
void initBoard(vector<vector<char>> &grid, string fileName)
{
    ifstream file(fileName);
    string line;
    getline(file, line); // skip first line
    ///vector<std::vector<char>> grid;

    while(getline(file, line))
    {
        vector<char> insideV (line.begin(), line.end()); // read string into vector of char
        grid.push_back(insideV);
    }
        cout << "PROCESSING ROW INPUT BOARD" << endl;
    ///remove chars we don't want
    for (int i = 0; i < grid.size(); i++ )
    {
        for (int n = 0; n < grid.at(i).size(); n++)
        {
            if (grid[i][n] != 'M' ||grid[i][n] != '#' || grid[i][n] != ' '|| grid[i][n] == ',')
            {
                grid[i].erase(grid[i].begin()+n);
            }

        }
    }
    ///remove more stuff that we missed on the first pass for some odd reason...
    for (int i = 0; i < grid.size(); i++ )
    {
        for (int n = 0; n < grid.at(i).size(); n++)
        {
            if (grid[i][n] == '{' ||grid[i][n] == ','||grid[i][n] == ';'||grid[i][n] == '\'')
            {
                grid[i].erase(grid[i].begin()+n);
            }

        }
    }
    ///remove more stuff that we missed on the first pass for some odd reason...
    for (int i = 0; i < grid.size(); i++ )
    {
        for (int n = 0; n < grid.at(i).size(); n++)
        {
            if (grid[i][n] == '{' ||grid[i][n] == ','||grid[i][n] == ';'||grid[i][n] == '\'')
            {
                grid[i].erase(grid[i].begin()+n);
            }

        }
    }
    ///erase the last three rows unconditionally
    ///they only contain row col and closing braces
    grid.erase(grid.end());
    grid.erase(grid.end());
    grid.erase(grid.end());
    ROWS = grid.size();
    COLS = grid[0].size();
    cout << "ROWS DEBUG: " << ROWS << endl;
    cout << "COLS DEBUG: " << COLS << endl;

    file.close();
}
///stolen from here
///http://www.unix.com/programming/20438-unbuffered-streams.html
int getch(void) {
      int c=0;

      struct termios org_opts, new_opts;
      int res=0;
          //-----  store old settings -----------
      res=tcgetattr(STDIN_FILENO, &org_opts);
      assert(res==0);
          //---- set new terminal parms --------
      memcpy(&new_opts, &org_opts, sizeof(new_opts));
      new_opts.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ECHOPRT | ECHOKE | ICRNL);
      tcsetattr(STDIN_FILENO, TCSANOW, &new_opts);
      c=getchar();
          //------  restore old settings ---------
      res=tcsetattr(STDIN_FILENO, TCSANOW, &org_opts);
      assert(res==0);
      return(c);
}
///stolen from here
///https://cboard.cprogramming.com/c-programming/63166-kbhit-linux.html
int kbhit (void)
{
  struct timeval tv;
  fd_set rdfs;
 
  tv.tv_sec = 0;
  tv.tv_usec = 0;
 
  FD_ZERO(&rdfs);
  FD_SET (STDIN_FILENO, &rdfs);
 
  select(STDIN_FILENO+1, &rdfs, NULL, NULL, &tv);
  return FD_ISSET(STDIN_FILENO, &rdfs);
 
}
///stolen from here
///https://cboard.cprogramming.com/c-programming/63166-kbhit-linux.html
void changemode(int dir)
{
  static struct termios oldt, newt;
 
  if ( dir == 1 )
  {
    tcgetattr( STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newt);
  }
  else
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt);
}
 
