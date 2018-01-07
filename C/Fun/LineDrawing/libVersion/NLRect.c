#include "Shapes.h"
void drawRect(double x, double y, double l, double h)
{
    drawLSeg(x,y,x+l,y);
    drawLSeg(x,y+h,x+l,y+h);
    drawLSeg(x+l,y,x+l,y+h);
    drawLSeg(x,y,x,y+h);
}

void drawRRect(double x, double y, double l, double h, double cx, double cy, double deg)
{
    Pair rpair1 = rotateDPoint(cx,cy,x,y,deg);
    Pair rpair2 = rotateDPoint(cx,cy,x+l,y,deg);
    Pair rpair3 = rotateDPoint(cx,cy,x,y+h,deg);
    Pair rpair4 = rotateDPoint(cx,cy,x+l,y+h,deg);

    drawLSeg(rpair1.x,rpair1.y,rpair2.x,rpair2.y);
    drawLSeg(rpair3.x,rpair3.y,rpair4.x,rpair4.y);
    drawLSeg(rpair2.x,rpair2.y,rpair4.x,rpair4.y);
    drawLSeg(rpair1.x,rpair1.y,rpair3.x,rpair3.y);
}
