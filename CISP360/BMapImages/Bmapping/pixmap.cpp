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
            temp[i][n].blue = rand() % COLOR_DEPTH;
            temp[i][n].green = rand() % COLOR_DEPTH;
            temp[i][n].red = rand() % COLOR_DEPTH;
            temp[i][n].reserved = 0;
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
            temp[i][n].blue = 255;
            temp[i][n].green = 255;
            temp[i][n].red = 255;
            temp[i][n].reserved = 0;
        }
    }

    ///the left side will be set to a five pixel black strip
    for (int i = 0; i < row; i++)
    {
        for (int n = 0; n < 5; n++)
        {
            temp[i][n].blue = 0;
            temp[i][n].green = 0;
            temp[i][n].red = 0;
            temp[i][n].reserved = 0;
        }
    }
    ///now the right side
    for (int i = 0; i < row; i++)
    {
        for (int n = col-1; n > col-10; n--)
        {
            temp[i][n].blue = 0;
            temp[i][n].green = 0;
            temp[i][n].red = 0;
            temp[i][n].reserved = 0;
        }
    }
    ///now the top strip, but I feel like seven looks nicer
    for (int i = 0; i < 7; i++)
    {
        for (int n = 0; n < col; n++)
        {
            temp[i][n].blue = 255;
            temp[i][n].green = 255;
            temp[i][n].red = 255;
            temp[i][n].reserved = 0;
        }
    }
    ///now the top strip
    for (int i = row-1; i > row-9; i--)
    {
        for (int n = 0; n < col; n++)
        {
            temp[i][n].blue = 255;
            temp[i][n].green = 255;
            temp[i][n].red = 255;
            temp[i][n].reserved = 0;
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
//
//int writeBMP(Pixel** image, string fileName, int row, int col)
//{
//
//    cout << "BITMAP!" << endl;
//    string fname = fileName + ".bmp";
//    ofstream outFile;
//    cout << "Opening your file..." << endl;
//
//    BITMAPFILEHEADER fileHDR;
//    fileHDR.bfType = 0xDEAD;
//    fileHDR.bfReserved1 = 0;
//    fileHDR.bfReserved2 = 0;
//    fileHDR.bfOffBits = 14+40;
//
//    BITMAPINFOHEADER infoHDR;
//    infoHDR.biSize = 40;
//    infoHDR.biWidth = col;
//    infoHDR.biHeight = row;
//    infoHDR.biPlanes = 1;
//    infoHDR.biBitCount = 8;
//    infoHDR.biCompression = 0;
//    infoHDR.biSizeImage = 0;
//    infoHDR.biXPelsPerMeter = 0;
//    infoHDR.biYPelsPerMeter = 0;
//    infoHDR.biClrUsed = 0;
//    infoHDR.biClrImportant = 0;
//
//    fileHDR.bfSize = (sizeof(Pixel)*row*col)+(sizeof(fileHDR))+(sizeof(infoHDR));
//    outFile.write((char*)(&fileHDR),14);
//    outFile.write((char*)(&infoHDR),40);
////    ///initialize the uninitialized fields of the info and file header structs
////    BitFH fileHdr;
////    fileHdr.fileSize = (sizeof(Pixel)*row*col)+(sizeof(BitFH))+(sizeof(BitIH));
////    fileHdr.offsetToBmp = 1078; ///this is just the offset they use in the example I read..
////
////    ///setup the info header too
////    BitIH infoHdr;
////    infoHdr.imgWidth = col;
////    infoHdr.imgHeight = row;
//
//    ///BMP files have a file header and an info header
//    cout << "Writing BMP file header..." << endl;
////    outFile.open(fname, ios::binary);
//////    outFile << fileHdr.fileType;
////   // outFile << fileHdr.fileSize;
////    //outFile << fileHdr.reserved1;
////    //outFile  << fileHdr.reserved2;
////    outFile <<  0x00;
//////    outFile << fileHdr.offsetToBmp;
//
//    cout << "Writing BMP info header" << endl;
////    outFile << infoHdr.infoHdrSz;
////    outFile << infoHdr.imgWidth;
////    outFile << infoHdr.imgHeight;
////    outFile << infoHdr.cPlanes;
////    outFile << infoHdr.bpp;
////    outFile << infoHdr.compression;
////    outFile << infoHdr.imgSz;
////    outFile << infoHdr.hPixPerM;
////    outFile << infoHdr.vPixPerM;
////    outFile << infoHdr.colorsUsed;
////    outFile << infoHdr.importantColors;
//
//    cout << "File header written..." << endl;
//
//    ///we must close and reopen to append the binary image data
//    outFile.close();
//    outFile.open(fname, ios::app | ios::binary |ios::out);    ///append in binary mode
//
//    cout << "Writing your file..." << endl;
//    for (int i = 0; i < row; i++)
//    {
//        for (int n = 0; n < col; n++)
//        {
//            outFile << image[i][n].blue;
//            outFile << image[i][n].green;
//            outFile << image[i][n].red;
//            outFile << image[i][n].reserved;
//        }
//    }
//    outFile.close();
//    return 1;
//}

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

///this is all windows specific if you take a peek above you will see that I utterly failed at this..
///https://stackoverflow.com/questions/18838553/c-how-to-create-a-bitmap-file
void writeHeader(ostream& out, int width, int height)
{
    if (width % 4 != 0)
    {
        cerr << "ERROR: There is a windows-imposed requirement on BMP that the width be a multiple of 4.\n";
        cerr << "Your width does not meet this requirement, hence this will fail.  You can fix this\n";
        cerr << "by increasing the width to a multiple of 4." << endl;
        exit(1);
    }

    BITMAPFILEHEADER fileHDR;
    fileHDR.bfType = 0x4d42;    ///'BM'
    ///fileHDR.bfSize = 14 + 40 + (width*height*4); nothing seems to be calculating this right and it doesn't seem needed
    fileHDR.bfSize = 0;                          ///so we might as well set it to zero..
    fileHDR.bfReserved1 = 0;
    fileHDR.bfReserved2 = 0;
    fileHDR.bfOffBits = 14 + 40;                ///where the headers end and the image data begins

    BITMAPINFOHEADER infoHDR;
    memset(&infoHDR,0,40);
    infoHDR.biSize = 40;
    infoHDR.biWidth = width;
    infoHDR.biHeight = height;
    infoHDR.biPlanes = 1;
    infoHDR.biBitCount = 24;                    ///one per color plus one more reserved one for zeros
    infoHDR.biCompression = 0;

    ///fileHDR.bfSize = sizeof(fileHDR) + sizeof(infoHDR) + sizeof(uint8_t) * width * height * 4;
    ///write both headers to the file
    out.write((char*)(&fileHDR),14);
    out.write((char*)(&infoHDR),40);
}
void makeBMP(Pixel** image, string fileName, int row, int col)
{
    ofstream ofs;
    ofs.open(fileName + ".bmp");
    writeHeader(ofs, row, col);
    cout << "Writing your file..." << endl;
    for (int i = 0; i < row; i++)
    {
        for (int n = 0; n < col; n++)
        {
            ofs << image[i][n].blue;
            ofs << image[i][n].green;
            ofs << image[i][n].red;
            ofs << image[i][n].reserved;
        }
    }
}
