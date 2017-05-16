#include <iostream>
#include <cstdlib>
///wait function:
///conio is not portable you should use pdcurses/ncurses instead
#include <conio.h>
//need for Sleep(ms)
#include <windows.h>
///random functions
#include <ctime>
using namespace std;
//idea1: update array thru shared timer
//globals for convenience
const char ROWS = 20;
const char COLS = 20;
//globals for current position on board
int playerRow = 0;
int playerCol = 0;
//function prototypes
//to display the board
void dispBoard(char[ROWS][COLS]);
///clear the previous board..
void refreshBoard();
/*user input*/

/*initialize a board*/
void initBoard(char[ROWS][COLS]);
int moveSpot(char[ROWS][COLS]);

//check for a win
int checkBoard(char[ROWS][COLS]);
//move all the monsters
void moveMonsters(char[ROWS][COLS]);
//move a single monster
int moveMonster(char[ROWS][COLS], int, int, int);
int main()
{
    srand(time(0));
    int endFlag = 0;
    //char board[ROWS][COLS];
    //a debugging board
    char board[20][20] =
    {
        {' ','#','@',' ','@',' ','#',' ',' ',' ',' ','#',' ',' ','M',' ','#',' ',' ','#',},
        {'@','#','@','#','@',' ','#',' ',' ','#',' ','#',' ',' ',' ',' ','#',' ','#',' ',},
        {'@','#',' ','#','@',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ',},
        {'@','#','@','#','@',' ','#',' ','M','#',' ','#','#','#',' ',' ',' ',' ',' ',' ',},
        {'@','@','@','#','@','M',' ','@',' ',' ',' ','#',' ','@',' ','#','#',' ','M','#',},
        {' ','#','@',' ','@','@','#','#',' ',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ',},
        {' ','#','@','#','@',' ','#',' ',' ','#',' ','#','@','#','#',' ',' ',' ','#',' ',},
        {' ','#','@','#','@',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ',},
        {' ','#','@','#','@','#','#',' ','#',' ',' ','#',' ',' ',' ',' ','#',' ',' ','#',},
        {' ','#','@','#','@',' ','#','#',' ',' ',' ','#',' ',' ','M',' ','#',' ','#',' ',},
        {'@','#',' ','#','#','#','#',' ','#','#','#','#','#','#',' ',' ','#',' ',' ',' ',},
        {' ','#',' ','#',' ','@','#',' ',' ','#',' ','#',' ','#',' ',' ','#','@','#',' ',},
        {' ','#',' ','#','#',' ','#',' ',' ',' ',' ','#',' ','#',' ',' ','#','#',' ',' ',},
        {' ','#','@','#','@',' ','#',' ','M',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',},
        {' ','#',' ',' ',' ',' ',' ','#',' ','#',' ','#',' ','#',' ',' ','#',' ',' ',' ',},
        {' ','#',' ','#','#','#','#',' ',' ',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ',},
        {' ','#','@','#',' ','#','#','#','#','#','#',' ',' ','#',' ',' ',' ','@','#',' ',},
        {' ','#','#','#',' ',' ',' ',' ',' ','#',' ','#',' ','#','#','#','#',' ','#','@',},
        {'@',' ',' ',' ','@',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ','#',' ',},
        {'@',' ',' ','#','@','#','#',' ',' ',' ',' ','#',' ',' ','#','#','#','#','#',' ',}
    };
    //initBoard(board);
    board[playerRow][playerCol] = '0';
    //the game loop
    do
    {
        dispBoard(board);
        endFlag = moveSpot(board);
        if (endFlag == -1)
            return 0;
        //check for a win
        moveMonsters(board);
        endFlag = checkBoard(board);
    }
    while (endFlag == 0);

    return 0;
}
int moveSpot( char arr[ROWS][COLS])
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
            choice = _getch();
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
            refreshBoard();
            cout << "BANG YOU'RE DEAD!" << endl;
            return -1;
        }
    }
    while(arr[playerRow][playerCol] == '#');
    arr[playerRow][playerCol] = '0';
    return returnState;
}

void dispBoard(char arr[ROWS][COLS])
{
    ///for some reason refresh board is fairly seizure inducing..
    ///since we've already sacrificed portability to use unbuffered io
    ///I feel it is safe to just use cls..
    system("cls");
    //refreshBoard();
    cout << "Eat the @'s, but don't get eaten by any monsters! (use w,a,s,d to move)" << endl;
    for (int i = 0; i < ROWS; i++)
    {
        for (int n = 0; n < COLS; n++)
            cout << arr[i][n] << " ";
        cout << endl;
    }
}

///we could use this to refresh the screen but pdcurses/ncurses is a better choice
void refreshBoard()
{
    for (int i = 0; i < 20; i++)
        cout << endl;
}

int checkBoard(char arr[ROWS][COLS])
{
    for(int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (arr[i][j] == '@')
                return 0;
        }
    }
    system("cls");
    cout << "GOOD JOB, YOU WON!" << endl;
    return 1;
}
void moveMonsters(char arr[ROWS][COLS])
{
    ///0 for up, 1 for down, 2 for left, 3 for right
    int retry = 0;
    int moveDirection = rand() % 3;
    do
    {
        for(int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (arr[i][j] == 'M')
                    retry = moveMonster(arr, i,j, moveDirection);
            }
        }
    }
    while (retry == -1);
    Sleep(0.1);
};

int moveMonster(char board[ROWS][COLS], int r, int c, int direction)
{
    //check for a wall or an @
    if (direction == 0 && board[row+1][col] == '#')
    {
        cout << "Can't move" << endl;
        exit(0);
        return -1;
    }
    else if (direction == 1 && board[row-1][col] == '#')
    {
        cout << "Can't move" << endl;
        exit(0);
        return -1;
    }
    else if (direction == 2 && board[row][col-1] == '#')
    {
        cout << "Can't move" << endl;
        exit(0);
        return -1;
    }
    else if (direction == 3 && board[row][col+1] == '#')
    {
        cout << "Can't move" << endl;
        exit(0);
        return -1;
    }
    else
    {
        cout << "Can't move" << endl;
        exit(0);
        return -1;
    }
    cout << row << " " << col;
    return 0;
};
