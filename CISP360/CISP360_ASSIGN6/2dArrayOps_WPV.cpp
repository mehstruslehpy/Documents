#include <iostream>

using namespace std;

///constants
const int ROWS = 4;
const int COLS = 5;

///function prototypes
///your version
int hermleTotal(int**, int, int);

///my versions
int myGetTotal(int*, int, int);
double myGetAverage(int*, int, int);
int myGetRowTotal(int*, int, int, int);
int myGetColumnTotal(int*, int, int, int);
int myGetLowestInRow(int *arr, int rows, int cols, int choice);
int myGetHighestInRow(int *arr, int rows, int cols, int choice);

///the ones you are asking for
double getAverage( int [ROWS][COLS]);
int getTotal( int [ROWS][COLS]);
int getRowTotal(int [ROWS][COLS], int);
int getColumnTotal(int [ROWS][COLS], int);
int getRowTotal(int [ROWS][COLS], int);
int getHighestInRow(int [ROWS][COLS], int);
int getLowestInRow(int [ROWS][COLS], int);

int main()
{

    ///the array you gave us
    int testArray[ROWS][COLS] =
    {
        { 1, 2, 3, 4, 5 },
        { 6, 7, 8, 9, 10 },
        { 11, 12, 13, 14, 15 },
        { 16, 17, 18, 19, 20 }
    };

    ///tons of output
    cout << "Normal total of the array: " << getTotal(testArray) << endl;
    cout << "Normal average of the array: " << getAverage(testArray) << endl<<endl;
    cout << "Total of row 0: " << getRowTotal(testArray, 0)
         << " Highest value is: " << getHighestInRow(testArray, 0)
         << " Lowest is: " << getLowestInRow(testArray, 0) << endl;
    cout << "Total of row 1: " << getRowTotal(testArray, 1)
         << " Highest value is: " << getHighestInRow(testArray, 1)
         << " Lowest is: " << getLowestInRow(testArray, 1) << endl;
    cout << "Total of row 2: " << getRowTotal(testArray, 2)
         << " Highest value is: " << getHighestInRow(testArray, 2)
         << " Lowest is: " << getLowestInRow(testArray, 2) << endl;
    cout << "Total of row 3: " << getRowTotal(testArray, 3)
         << " Highest value is: " << getHighestInRow(testArray, 3)
         << " Lowest is: " << getLowestInRow(testArray, 3) << endl;

    cout << "Total of column 0: " << getColumnTotal(testArray, 0) << endl;
    cout << "Total of column 1: " << getColumnTotal(testArray, 1) << endl;
    cout << "Total of column 2: " << getColumnTotal(testArray, 2) << endl;
    cout << "Total of column 3: " << getColumnTotal(testArray, 3) << endl;
    cout << "Total of column 4: " << getColumnTotal(testArray, 4) << endl << endl;

    cout << "My total of the array: " << myGetTotal((int*)testArray, ROWS, COLS) << endl;
    cout << "My average of the array: " << myGetAverage((int*)testArray, ROWS, COLS) << endl <<endl;
    cout << "My total of row 0: " << myGetRowTotal((int*)testArray, ROWS, COLS, 0)
         << " My Highest is: " << myGetHighestInRow((int*)testArray, ROWS, COLS, 0)
         << " Lowest is: " << myGetLowestInRow((int*)testArray, ROWS, COLS, 0) << endl;
    cout << "My total of row 1: " << myGetRowTotal((int*)testArray, ROWS, COLS, 1)
         << " My Highest is: " << myGetHighestInRow((int*)testArray, ROWS, COLS, 1)
         << " Lowest is: " << myGetLowestInRow((int*)testArray, ROWS, COLS, 1) << endl;
    cout << "My total of row 2: " << myGetRowTotal((int*)testArray, ROWS, COLS, 2)
         << " My Highest is: " << myGetHighestInRow((int*)testArray, ROWS, COLS, 2)
         << " Lowest is: " << myGetLowestInRow((int*)testArray, ROWS, COLS, 2) << endl;
    cout << "My total of row 3: " << myGetRowTotal((int*)testArray, ROWS, COLS, 3)
         << " My Highest is: " << myGetHighestInRow((int*)testArray, ROWS, COLS, 3)
         << " Lowest is: " << myGetLowestInRow((int*)testArray, ROWS, COLS, 3) << endl;

    cout << "My total of column 0: " << myGetColumnTotal((int*)testArray, ROWS, COLS, 0) << endl;
    cout << "My total of column 1: " << myGetColumnTotal((int*)testArray, ROWS, COLS, 1) << endl;
    cout << "My total of column 2: " << myGetColumnTotal((int*)testArray, ROWS, COLS, 2) << endl;
    cout << "My total of column 3: " << myGetColumnTotal((int*)testArray, ROWS, COLS, 3) << endl;
    cout << "My total of column 4: " << myGetColumnTotal((int*)testArray, ROWS, COLS, 4) << endl;

    ///a call to my versions generally works like this..
    ///myFunctions((int *)2DArray, rows, cols, sometimesAChoiceHere);

    return 0;

}
///this was the one you worked on
int hermleTotal(int **arr, int rows, int cols)
{
    int accumulator = 0;
    cout << arr[0] << endl;
    cout << arr[1] << endl;
    for (int i = 0; i < (rows); i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout << (int)arr[i*cols + j] << endl;
            accumulator += (int)arr[i*cols + j];
        }
    }
    return accumulator;
}

///arrays are flat in memory so you only need a one dimensional array
///to iterate across a two dimensional array..
///for example: arr[3][3]
///assuming row major ordering our array will looks like this:
///
///     row0      |  row1      | row2
///     [0][1][2] |  [0][1][2] | [0][1][2]
///
///sometimes I mix up the two orderings so this may be column major
///but which one in particular is irrelevant the length to iterate across
///a two dimensional array in one dimension will always be rows*cols and
///we only ever need to iterate by the size of the type in the array

///I looked up the issue of the pointer to pointer two-dimensional array and most SO posts I found
///stated they are not exactly the same thing, though c != c++ so maybe the two languages have subtle
///differences in regards to this issue?

///https://stackoverflow.com/questions/1052818/create-a-pointer-to-two-dimensional-array
///https://stackoverflow.com/questions/10165627/how-to-assign-two-dimensional-array-to-pointer
///https://stackoverflow.com/questions/7586702/is-2d-array-a-double-pointer
///https://stackoverflow.com/questions/7351331/please-explain-the-ambiguity-in-pointers-in-c/7351390#7351390

///my opinion after bashing my head against this issue is that if you want to pass a two-dimensional array to
///a function the best option is to pass a pointer to the first element and the rows and columns. With that
///information you can either access the array as a one dimensional array as in this function, or you can set up
///a local two dimensional array/pointer-to-an-array/etc built from the original arrays dimensions and the pointer

int myGetTotal(int *arr, int rows, int cols)
{
    int accumulator = 0;

    for (int i = 0; i < (rows * cols); i++)
    {
        accumulator += arr[i];
    }
    return accumulator;
}

///I also figured out a similar way of iterating across a passed in two dimensional array
///without deviating from the style of function calls I have already been using
int myGetRowTotal(int *arr, int rows, int cols, int choice)
{
    int accumulator =0;
    for (int i = 0; i < cols; i++)
    {
        accumulator += *(arr+choice*cols+i);///after a lot of trial and error I figured this out
    }
    return accumulator;
}
int myGetColumnTotal(int *arr, int rows, int cols, int offset)
{
    int accumulator =0;
    for (int i = 0; i < rows; i++)
    {
        ///out << "ARRAY: " << *(arr+(i*5)+offset) << endl;
        accumulator += *(arr+(i*5)+offset);///this was a nightmare and it took forever!!
    }
    return accumulator;
}
int getTotal(int arr[ROWS][COLS])
{
    int accumulator = 0;
    for (int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            accumulator += arr[i][j];
        }
    }
    return accumulator;
}
///this works out to be basically the same as the first func but we need to return accum / (rows*cols)
///so long as we return a double and accumulate with a double everything should get promoted successfully
double myGetAverage(int* arr, int rows, int cols)
{
    double accumulator = 0;
    for (int i = 0; i < (rows * cols); i++)
    {
        accumulator += arr[i];
    }
    return (accumulator / (rows * cols));
}
double getAverage(int arr[ROWS][COLS])
{
    double accumulator = 0;
    for (int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            accumulator += arr[i][j];
        }
    }
    return (accumulator/(ROWS*COLS));
}
int getRowTotal(int arr[ROWS][COLS], int row)
{
    int accumulator =0;
    for (int i = 0; i < COLS; i++)
    {
        accumulator += arr[row][i];
    }
    return accumulator;
}
int getColumnTotal(int arr[ROWS][COLS], int col)
{
    int accumulator =0;
    for (int i = 0; i < ROWS; i++)
    {
        accumulator += arr[i][col];
    }
    return accumulator;
}
int getHighestInRow(int arr[ROWS][COLS], int row)
{
    int value =0;
    value = arr[row][0];
    for (int i = 0; i < COLS; i++)
    {
        if (value < arr[row][i])
        {
            value = arr[row][i];
        }
    }
    return value;
}
int getLowestInRow(int arr[ROWS][COLS], int row)
{
    int value =0;
    value = arr[row][0];
    for (int i = 0; i < COLS; i++)
    {
        if (value > arr[row][i])
        {
            value = arr[row][i];
        }
    }
    return value;
}
int myGetLowestInRow(int *arr, int rows, int cols, int choice)
{
    int temp = *(arr+choice*cols+0);
    for (int i = 0; i < cols; i++)
    {
        if ( temp > *(arr+choice*cols+i))
        {
            temp = *(arr+choice*cols+i);
        }
    }
    return temp;
}
int myGetHighestInRow(int *arr, int rows, int cols, int choice)
{
    int temp = *(arr+choice*cols+0);
    for (int i = 0; i < cols; i++)
    {
        if ( temp < *(arr+choice*cols+i))
        {
            temp = *(arr+choice*cols+i);
        }
    }
    return temp;
}


