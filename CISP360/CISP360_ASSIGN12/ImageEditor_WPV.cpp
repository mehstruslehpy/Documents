//Image Editor
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

enum {BLUE, GREEN, RED};

const int COLORS_PER_PIXEL = 3;
const int BMP_HEADER_SIZE = 54;

struct Image
{
    int pixelDataOffset;
    int pixelCols;
    int pixelRows;
    int rowPadding;
    string fileName;
    unsigned char ***pixels;
};

void readImage(Image &, fstream &);
void writeImage(Image, fstream &);
void deallocate(Image &);

int main()
{
    fstream f1; ///the first input file
    fstream f2; ///the second input file
    Image img1; ///the first input image
    Image img2; ///the second input image
    int smallRow;
    int smallCol;
    bool toggle = true;

    ///the user will pick filenames
    cout << "Enter file name 1 WITHOUT the extension: ";
    cin >> img1.fileName;
    cout << "Enter file name 2 WITHOUT the extension: ";
    cin >> img2.fileName;
    img1.fileName += ".bmp";
    img2.fileName += ".bmp";

    ///open the files
    cout << "Attempting to open \"" << img1.fileName << "\"..." << endl;
    f1.open(img1.fileName.c_str(), ios::in | ios::out | ios::binary);
    cout << "Attempting to open \"" << img2.fileName << "\"..." << endl;
    f2.open(img2.fileName.c_str(), ios::in | ios::out | ios::binary);

    ///this is a modification of an idea from here:
    ///https://stackoverflow.com/questions/10195343/copy-a-file-in-a-sane-safe-and-efficient-way#10195497
    ///the idea is to do a quick copy of the file to be clobbered
    ifstream  src(img2.fileName.c_str(), ios::binary);
    ofstream  dst("backup.bmp", ios::binary);
    dst << src.rdbuf();
    src.close();
    dst.close();

    ///if either of them fail print an error
    if(f1.fail() || f2.fail())
    {
        cout << "Error opening the file" << endl;
        cout << "file one status: " << f1.fail() << endl;
    }
    else
    {
        cout << "Files opened successfully" << endl;

        ///read each image
        readImage(img1, f1);
        readImage(img2, f2);
        f1.clear();
        f1.seekg(0,ios::beg);
        f2.clear();
        f2.seekg(0,ios::beg);


        ///find the smaller row/col bounds
        smallRow = (img1.pixelRows < img2.pixelRows) ? img1.pixelRows : img2.pixelRows;
        smallCol = (img1.pixelCols < img2.pixelCols) ? img1.pixelCols : img2.pixelCols;

        ///overlay the images
        for(int i = 0; i < smallRow; i++)
        {
            for(int j = 0; j < smallCol; j++)
            {
                ///overwrite every other iteration
                if (toggle == true)
                {
                    ///loop through each pixel
                    img2.pixels[i][j][BLUE] = img1.pixels[i][j][BLUE];
                    img2.pixels[i][j][GREEN] = img1.pixels[i][j][GREEN];
                    img2.pixels[i][j][RED] = img1.pixels[i][j][RED];
                }
                toggle = !toggle; ///this
            }


        }

        writeImage(img2, f2);
        deallocate(img1);
        deallocate(img2);
    }
    f1.close();
    f2.close();
    return 0;
}

///This function reads the pixel data from the file and loads it into the Image struct
void readImage(Image &img, fstream &f)
{
    unsigned char header[BMP_HEADER_SIZE];
    f.read((char*)header, sizeof(unsigned char) * BMP_HEADER_SIZE);
    img.pixelDataOffset = *((int*)(header + 10));
    img.pixelRows = *((int*)(header + 22));
    img.pixelCols = *((int*)(header + 18));

    ///Weird code that adds "padding" to the rows
    ///to make their size a multiple of 4
    int rowBytes = img.pixelCols * COLORS_PER_PIXEL;
    rowBytes = (rowBytes + 3) & (~3); ///bitwise round up to multiple of 4
    img.rowPadding = rowBytes - img.pixelCols * COLORS_PER_PIXEL;

    cout << "File name: " << img.fileName << endl;
    cout << "Pixel data offset: " << img.pixelDataOffset << endl;
    cout << "Pixel Height: " << img.pixelRows << endl;
    cout << "Pixel Width: " << img.pixelCols << endl;
    cout << "Number of extra padding bytes in each row: " << img.rowPadding << endl;

    ///Allocate the pixel array on the heap
    img.pixels = new unsigned char**[img.pixelRows]; ///each row points to an array of columns each of which points to 3 bytes (BGR)

    for(int i = 0; i < img.pixelRows; i++)
    {
        img.pixels[i] = new unsigned char*[img.pixelCols]; ///each row points to an array of columns

        for(int j = 0; j < img.pixelCols; j++)
        {
            img.pixels[i][j] = new unsigned char[COLORS_PER_PIXEL]; ///each row / col pair points to 3 pixel bytes (BGR)
        }
    }

    f.clear();
    f.seekg(img.pixelDataOffset, ios::beg); ///seek to the beginning of the pixel data

    for(int i = 0; i < img.pixelRows; i++)
    {
        for(int j = 0; j < img.pixelCols; j++)
        {
            img.pixels[i][j][BLUE] = f.get();
            img.pixels[i][j][GREEN] = f.get();
            img.pixels[i][j][RED] = f.get();
        }

        for(int j = 0; j < img.rowPadding; j++)
        {
            f.get(); ///consume extra bytes for row padding
        }
    }
}

///This function writes the pixel data from the Image struct back into the file
void writeImage(Image img, fstream &f)
{
    f.clear();
    f.seekg(img.pixelDataOffset, ios::beg); ///seek to the beginning of the pixel data

    for(int i = 0; i < img.pixelRows; i++)
    {
        for(int j = 0; j < img.pixelCols; j++)
        {
            f.put(img.pixels[i][j][BLUE]);
            f.put(img.pixels[i][j][GREEN]);
            f.put(img.pixels[i][j][RED]);
        }

        for(int j = 0; j < img.rowPadding; j++)
        {
            f.put(0); ///fill in row padding with null bytes
        }
    }
}

void deallocate(Image &img)
{
    for(int i = 0; i < img.pixelRows; i++)
    {
        for(int j = 0; j < img.pixelCols; j++)
        {
            delete[] img.pixels[i][j]; ///delete BGR pointer in the row
        }
        delete[] img.pixels[i]; ///delete each row pointer
    }
    delete[] img.pixels;  ///delete the array of row pointers
}
