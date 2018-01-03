#include "Shapes.h"
void drawTri(double x1, double y1, double x2, double y2, double x3, double y3)
{
    if (!checkPair(x1,y1) || !checkPair(x2,y2) || !checkPair(x2,y2)) return;
    drawLSeg(x1,y1,x2,y2);
    drawLSeg(x1,y1,x3,y3);
    drawLSeg(x2,y2,x3,y3);
}
