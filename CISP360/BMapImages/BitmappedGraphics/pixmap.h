#include <iostream>
#include <time.h>
#include <cstdlib>
#include <fstream>
#include <string>

///this will come in handy later
#define COLOR_DEPTH 255
///the basic structure

struct Pixel
{
    ///an unsigned char can be 0 -> 255
    unsigned char red;
    unsigned char green;
    unsigned char blue;
};

///to initialize (or free) each pixel in the image to a random color
///maybe later we will do this with vectors
extern Pixel** initImageRand(int, int);
extern Pixel** initImageBordered(int, int);
extern int freeImage(Pixel**, int, int);
///print an ascii representation of the file (for debugging)
extern void printAsciiImage(Pixel**, int, int);
extern int writePPM(Pixel**, std::string, int, int);


