#include "Shapes.h"
void drawSqr(double x, double y, double l)
{
    drawLSeg(x,y,x+l,y);
    drawLSeg(x,y,x,y+l);
    drawLSeg(x+l,y,x+l,y+l);
    drawLSeg(x,y+l,x+l,y+l);
}

