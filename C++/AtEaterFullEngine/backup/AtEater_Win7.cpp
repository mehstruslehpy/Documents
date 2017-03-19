///TODO: fix the monster teleporting glitch
///      prevent the monsters from eating each other
#include <iostream>
#include <stdlib.h>
#include <ctime>
///needed for Sleep possibly
///conio is not portable you should use pdcurses/ncurses instead
#include <conio.h>
///need vectors because I'm lazy
#include <vector>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

//globals for convenience
int ROWS = 0;
int COLS = 0;
///globals for current position on board
int playerRow = 0;
int playerCol = 0;
///function prototypes
//to display the board
void dispBoard(vector<vector<char>>);
///clear the previous board..
void refreshBoard();
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
    if (argc==2)
    {
        ///if they specified a map via standard input
        initBoard(board, argv[1]);
    }
    else
    {
        cout << "Please specify a map to load: " << endl;
        getline(cin, mapName);
        initBoard(board, mapName);
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
    system("PAUSE");
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
            ///choice = _getch();
            choice = getinput();
            ///these can be used to change game-refresh rate
            goodInput = true;
            Sleep(100);
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
            system("PAUSE");
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
    system("PAUSE");
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
        system("PAUSE");

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

///from here
///http://www.cplusplus.com/forum/windows/1126/
char getinput()
{
    if (_kbhit())
    {
        ///_getch(); // edit : if you want to check the arrow-keys you must call getch twice because special-keys have two values
        ///return _getch();
        return _getch();
    }
    return 0; // if no key is pressed
}

///from here
///http://www.cplusplus.com/articles/4z18T05o/
void ClearScreen()
{
    HANDLE                     hStdOut;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD                      count;
    DWORD                      cellCount;
    COORD                      homeCoords = { 0, 0 };

    hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
    if (hStdOut == INVALID_HANDLE_VALUE) return;

    /* Get the number of cells in the current buffer */
    if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
    cellCount = csbi.dwSize.X *csbi.dwSize.Y;

    /* Fill the entire buffer with spaces */
    if (!FillConsoleOutputCharacter(
                hStdOut,
                (TCHAR) ' ',
                cellCount,
                homeCoords,
                &count
            )) return;

    /* Fill the entire buffer with the current colors and attributes */
    if (!FillConsoleOutputAttribute(
                hStdOut,
                csbi.wAttributes,
                cellCount,
                homeCoords,
                &count
            )) return;

    /* Move the cursor home */
    SetConsoleCursorPosition( hStdOut, homeCoords );
}

///we could use this to refresh the screen but pdcurses/ncurses is a better choice
void refreshBoard()
{
    for (int i = 0; i < 20; i++)
        cout << endl;
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
    cout << "WARNING THE MAPPING PROGRAM OUT PUTS AN OFF" << endl << "BY ONE ROW COUNT" << endl;
    ROWS = grid.size();
    COLS = grid[0].size();
    cout << "ROWS DEBUG: " << ROWS << endl;
    cout << "COLS DEBUG: " << COLS << endl;

    file.close();
}
