#include "pixmap.h"

using namespace std;


Pixel** initImageRand(int row, int col)
{
    Pixel** temp;
    temp = new Pixel*[row]; ///init all the rows
    cout << "Initializing the image..." << endl;
    ///go across each from left to right assigning memory and initializing values
    for (int i = 0; i < row; i++)
    {
        temp[i] = new Pixel[col];
        for (int n = 0; n < col; n++)
        {
            temp[i][n].red = rand() % COLOR_DEPTH;
            temp[i][n].green = rand() % COLOR_DEPTH;
            temp[i][n].blue = rand() % COLOR_DEPTH;
        }
    }
    return temp;
}

Pixel** initImageBordered(int row, int col)
{
    Pixel** temp;
    temp = new Pixel*[row]; ///init all the rows
    cout << "Initializing the image..." << endl;
    ///go across each from left to right assigning memory and initializing values to white
    for (int i = 0; i < row; i++)
    {
        temp[i] = new Pixel[col];
        for (int n = 0; n < col; n++)
        {
            temp[i][n].red = 255;
            temp[i][n].green = 255;
            temp[i][n].blue = 255;
        }
    }

    ///the left side will be set to a five pixel black strip
    for (int i = 0; i < row; i++)
    {
        for (int n = 0; n < 5; n++)
        {
            temp[i][n].red = 0;
            temp[i][n].green = 0;
            temp[i][n].blue = 0;
        }
    }
    ///now the right side
    for (int i = 0; i < row; i++)
    {
        for (int n = col-1; n > col-10; n--)
        {
            temp[i][n].red = 0;
            temp[i][n].green = 0;
            temp[i][n].blue = 0;
        }
    }
    ///now the top strip, but I feel like seven looks nicer
    for (int i = 0; i < 7; i++)
    {
        for (int n = 0; n < col; n++)
        {
            temp[i][n].red = 0;
            temp[i][n].green = 0;
            temp[i][n].blue = 0;
        }
    }
    ///now the top strip
    for (int i = row-1; i > row-9; i--)
    {
        for (int n = 0; n < col; n++)
        {
            temp[i][n].red = 0;
            temp[i][n].green = 0;
            temp[i][n].blue = 0;
        }
    }
    return temp;
}

void printAsciiImage(Pixel** image, int row, int col)
{
    ///go across each row from left to right and print each number as an ascii value
    for (int i = 0; i < row; i++)
    {
        cout << "COL NO: " << i << endl;
        for (int n = 0; n < col; n++)
        {
            cout << "R: " << image[i][n].red << " ";
            cout << "G: " << image[i][n].green << " ";
            cout << "B: " << image[i][n].blue << " ";
        }
        cout << endl;
        cout << endl;
    }
}

int writePPM(Pixel** image, string fileName, int row, int col)
{
    cout << "PIXMAP! (P6)" << endl;
    string fname = fileName + ".ppm";
    fstream outFile;
    cout << "Opening your file..." << endl;

    ///PPM headers are pure ascii so we can write the header easily
    outFile.open(fname, ios::out);
    outFile << "P6" << endl;
    outFile << "#By William Vanskike :D" << endl;
    outFile << col << " " << row << endl;
    outFile << COLOR_DEPTH << endl;
    cout << "File header written..." << endl;

    ///we must close and reopen to append the binary image data
    outFile.close();
    outFile.open(fname, ios::app | ios::binary|ios::out);    ///append in binary mode

    cout << "Writing your file..." << endl;
    for (int i = 0; i < row; i++)
    {
        for (int n = 0; n < col; n++)
        {
            outFile << image[i][n].red;
            outFile << image[i][n].green;
            outFile << image[i][n].blue;
        }
    }
    outFile.close();
    return 1;
}

int freeImage(Pixel **image, int row, int col)
{
    cout << "Uninitializing the image..." << endl;
    ///delete all the pointer to pointers
    for (int i = 0; i < row; i++)
    {
        ///one by one
        delete image[i];
    }
    ///delete the outer pointer
    delete image;
    return 1;
}
