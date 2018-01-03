#include "Shapes.h"
void drawRect(double x, double y, double l, double h)
{
    drawLSeg(x,y,x+l,y);
    drawLSeg(x,y+h,x+l,y+h);
    drawLSeg(x+l,y,x+l,y+h);
    drawLSeg(x,y,x,y+h);
}

