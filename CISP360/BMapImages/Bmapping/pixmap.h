#include <iostream>
#include <time.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include <windows.h>

///this will come in handy later
#define COLOR_DEPTH 255
///the basic structure
using namespace std;
struct Pixel
{
    ///this should be 0 -> 255... Maybe it's 0 -> 254? I don't know
    ///but if it doesn't work correctly just use unsigned chars instead
    uint8_t blue;   ///bmp uses bgr-reserved format so we might as well do that
    uint8_t green;  ///here too
    uint8_t red;
    uint8_t reserved;


};

///https://web.archive.org/web/20080912171714/http://www.fortunecity.com/skyscraper/windows/364/bmpffrmt.html
///the file header
//struct BitFH
//{
//    uint8_t fileType[2] = {'B','M'};  ///this is always "ascii B + ascii M"
//    uint32_t fileSize;
//    uint8_t reserved1[2] = {0x0,0x0}; ///always 0 for some reason
//    uint8_t reserved2[2] = {0x0,0x0}; ///same
//    uint32_t offsetToBmp;   ///the offset to the actual bmp data
//};
//
/////the bmp info header
//struct BitIH
//{
//    uint32_t infoHdrSz = 40;    ///the size of this header
//    uint32_t imgWidth;          ///image width in pixels
//    uint32_t imgHeight;         ///image height in pixels
//    uint16_t cPlanes = 1;       ///the number of color planes (everywhere I read says this should be 1)
//    uint16_t bpp = 8;           ///8 bits per pixel
//    uint32_t compression = '.';   ///who uses compression for a bitmap?!?
//    uint32_t imgSz = '.';         ///the image size apparently this can be zero if no compression is used
//    uint32_t hPixPerM = '.';      ///horizontal pixels per meter
//    uint32_t vPixPerM = '.';      ///vertical pixels per meter
//    uint32_t colorsUsed = '.';  ///specifies the number of colors if 0 use bpp
//    uint32_t importantColors = '.'; ///if 0 all colors are important
//};

///to initialize (or free) each pixel in the image to a random color
///maybe later we will do this with vectors
extern Pixel** initImageRand(int, int);
extern Pixel** initImageBordered(int, int);
extern int freeImage(Pixel**, int, int);
///print an ascii representation of the file (for debugging)
extern void printAsciiImage(Pixel**, int, int);
///extern int writeBMP(Pixel**, std::string, int, int);
extern void makeBMP(Pixel** image, string fileName, int row, int col);
