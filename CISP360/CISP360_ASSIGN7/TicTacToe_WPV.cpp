#include <iostream>
#include <limits>
//the normal define
#define MAX_INPUT_LENGTH numeric_limits<streamsize>::max()
using namespace std;

//globals for convenience
const char ROWS = 3;
const char COLS = 3;

//function prototypes
//to display the board
void dispBoard(char[ROWS][COLS]);

/*check functions*/
//check diagonally from the left down
bool checkDiagLD(char[ROWS][COLS], char);
//check diagonally from the left up
bool checkDiagLU(char[ROWS][COLS], char);
//check a single row or column
bool checkRow(char[ROWS][COLS], int, char);
bool checkCol(char[ROWS][COLS], int, char);
//check every single row and column
bool checkDiags(char[ROWS][COLS], char);
bool checkRows(char[ROWS][COLS], char);
bool checkCols(char[ROWS][COLS], char);
bool checkAll(char[ROWS][COLS], char);
bool checkSlotsOpen(char[ROWS][COLS]);
/*user input*/
void takeInput(char[ROWS][COLS], char);

/*initialize a board*/
void initBoard(char[ROWS][COLS]);

int main()
{
  cout << "NOTE: the board is resizable by modifying the constants ROWS and COLS at the top of the source" << endl;
  cout << "I tested that briefly with a 20 by 20 grid so your mileage may vary, your best chances of a playable game are with squares...";
  //set up the board
  //'*' will be unchosen
  //'X' will be player 1 X's
  //'O' will be player 
  bool winFlag = false;
  char board[ROWS][COLS];
  initBoard(board);
  
  //the game loop
  do {
    dispBoard(board);
    //if no asterisks are left on the board then most likely we've reached a draw state
    if (!checkSlotsOpen(board))
    {
      cout << "Draw!" << endl;
      break;
    }
    
    //player one
    cout << endl << "## X's turn ##" << endl;
    takeInput(board, 'X');
    if (checkAll(board, 'X'))
    {
      dispBoard(board);
      cout << "X's win!" << endl;
      break;
    }

    dispBoard(board);
    //if no asterisks are left on the board then most likely we've reached a draw state
    if (!checkSlotsOpen(board))
    {
      cout << "Draw!" << endl;
      break;
    }
    
    //player two
    cout << endl << "## O's turn ##" << endl;
    takeInput(board, 'O');
    if (checkAll(board, 'O'))
    {
      dispBoard(board);
      cout << "O's win!" << endl;
      break;
    }
    
  } while (!winFlag);
  //cout << "ROW CHECK: " << checkRow(board, 0, '*') << endl;
  //cout << "COL CHECK: " << checkCol(board, 1, '*') << endl;
  //cout << "ROWS CHECK: " << checkRows(board, '*') << endl;
  //cout << "COLS CHECK: " << checkCols(board, '*') << endl;
  //cout << "DIAGS CHECK: " << checkDiags(board, '*') << endl;
  //cout << "CHECK: " << checkAll(board, '*');
  return 0;
}

void dispBoard(char arr[ROWS][COLS])
{
  cout << "Board state: " << endl;
  //upper separators
  cout << "#";
  
  for(int i = 0; i < COLS; i++)
    cout << "####";
  cout << endl;
  
  for (int i = 0; i < ROWS; i++)
  {
    
    cout << "# ";
    for (int n = 0; n < COLS; n++)
      cout << arr[i][n] <<" # " ;
    cout << endl;
    cout << "#";
    for (int x = 0; x < COLS; x++)
      cout << "####";
    cout << endl;
  }
}

//check a single row
bool checkRow(char arr[ROWS][COLS], int rowChoice, char inChar)
{
  for (int i = 0; i < ROWS; i++)
  {
    if (arr[rowChoice][i] != inChar)
      return false;
  }
  return true;
}
//check a single column
bool checkCol(char arr[ROWS][COLS], int colChoice, char inChar)
{
  for (int i = 0; i < ROWS; i++)
  {
    if (arr[i][colChoice] != inChar)
      return false;
  }
  return true;
}

bool checkCols(char arr[ROWS][COLS], char inChar)
{
  bool flag = false;
  for (int i = 0; i < ROWS; i++)
  {
    if (checkCol(arr, i, inChar))
      flag = true;
  }
  return flag;
}

bool checkRows(char arr[ROWS][COLS], char inChar)
{
  bool flag = false;
  for (int i = 0; i < ROWS; i++)
  {
    if (checkRow(arr, i, inChar))
      flag = true;
  }
  return flag;
}

bool checkDiagLD(char arr[ROWS][COLS], char inChar)
{
  bool flag = true;
  //check from top left to bottom right
  for (int row = 0, col = 0; row < ROWS && col < COLS; row++, col++)
  {
      if (arr[row][col] != inChar)
	flag = false;
  }
  return flag;
}

bool checkDiagLU(char arr[ROWS][COLS], char inChar)
{
  bool flag = true;
  for (int row = ROWS-1, col = 0; row >= 0 && col <= COLS; row--, col++)
  {
    //to show indices or array elements of the diagonal
    //cout << "DEBUG: ";
    //cout << row << col << " ";
    //cout << arr[row][col] << " ";
    if (arr[row][col] != inChar)
      flag = false;
  }
  return flag;
}

bool checkDiags(char arr[ROWS][COLS], char inChar)
{
  //check both diagonals
  if (!checkDiagLU(arr, inChar) && !checkDiagLD(arr, inChar))
    return false;
  else
    return true;
}

bool checkAll(char arr[ROWS][COLS], char inChar)
{
  //if a check function returns true we know somebody has got a win so return true
  if ( checkRows(arr, inChar) || checkCols(arr, inChar) || checkDiags(arr, inChar) )
    //break
    return true;
  else
    return false;
}

void takeInput(char arr[ROWS][COLS], char inChar)
{   
    int row = 0;
    int col = 0;
    cout << "enter your row choice:" << endl;
    cin >> row;
    cin.ignore(256, '\n');
    cout << "enter your column choice:" << endl;
    cin >> col;
    cin.ignore(256, '\n');

    //check for errors
    //this will catch negative indices, indices greater than array bounds, fail bits, and strings in place of ints
    while (col > COLS - 1 || row > ROWS - 1 || cin.fail() || col < 0 || row < 0 || arr[row][col] != '*')
    {
      cout << "You entered an invalid input, please try again." << endl;
      if (cin.fail())
      {
	cin.clear();
	cin.ignore(MAX_INPUT_LENGTH, '\n');
      }
      cout << "enter your row choice:" << endl;
      cin >> row;
      cin.ignore(MAX_INPUT_LENGTH, '\n');
      cout << "enter your column choice:" << endl;
      cin >> col;
      cin.ignore(MAX_INPUT_LENGTH, '\n');
    }
    //cout << row << " " << col << endl;
    arr[row][col] = inChar;
}

void initBoard(char arr[ROWS][COLS])
{
  for(int i = 0; i < ROWS; i++)
  {
    for(int n = 0; n < COLS; n++)
    {
      arr[i][n] = '*';
    }
  }
}

bool checkSlotsOpen(char arr[ROWS][COLS])
{
  //flag for if viable moves still exist
  bool flag = false;

  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      if (arr[i][j] == '*')
	flag = true;
    }
  }
  return flag;
}
