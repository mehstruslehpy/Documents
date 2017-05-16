///everything is included via pixmap so we don't need
///anymore includes here. All of the structures and function
///prototypes are included via pixmap.h/pixmap.cpp
#include "pixmap.h"

using namespace std;

int main()
{

    srand(time(0));

    ///the first image
    Pixel** image1;
    int imageHeight1 = 1000;
    int imageWidth1 = 4000;
    string fname1 = "output1"; ///generic output filename

    ///the second image
    Pixel** image2;
    int imageHeight2 = 50;
    int imageWidth2 = 50    ;
    string fname2 = "output2"; ///generic output filename

    image1 = initImageRand(imageHeight1, imageWidth1);
    image2 = initImageBordered(imageHeight2, imageWidth2);
    cout << endl << "IMAGE1 " << endl;
    writePPM(image1, fname1, imageHeight1, imageWidth1);
    cout << endl << "IMAGE2" << endl;
    writePPM(image2, fname2, imageHeight2, imageWidth2);

    cout << endl;
    freeImage(image1, imageHeight1, imageWidth1);
    freeImage(image2, imageHeight2, imageWidth2);
    ///printAsciiImage(image, imageHeight1, imageHeight2);
    cin.get();

    return 0;
}
