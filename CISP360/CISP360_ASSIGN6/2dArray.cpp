#include <iostream>

using namespace std;
const int ROWS = 4;
const int COLS = 5;
int getTotal(int**, int, int);
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

    cout << testArray[0] << endl;
    cout << testArray[1] << endl;
    cout << "Total of array: " << getTotal((int**)testArray, ROWS, COLS) << endl;
}

int getTotal(int **arr, int rows, int cols)
{
    int accumulator = 0;
//    for (int i = 0; i < rows; i++)
//    {
//        for (int n = 0; n < cols; n++)
//        {
//            //accumulator = accumulator + *(arr+i*COLS + n);
//            //cout << arr[i][n] << endl;
//            accumulator = accumulator + arr[i][n];
//        }
//    }

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
