#include "Shapes.h"
void drawTri(double x1, double y1, double x2, double y2, double x3, double y3)
{
    //if (!checkPoint(x1,y1) || !checkPoint(x2,y2) || !checkPoint(x2,y2)) return;
    drawLSeg(x1,y1,x2,y2);
    drawLSeg(x1,y1,x3,y3);
    drawLSeg(x2,y2,x3,y3);
}
void drawRTri(double x1, double y1, double x2, double y2, double x3, double y3, double cx, double cy, double deg)
{
    //if (!checkPoint(x1,y1) || !checkPoint(x2,y2) || !checkPoint(x2,y2)) return;
    Pair rpair1 = rotateDPoint(cx,cy,x1,y1,deg);
    Pair rpair2 = rotateDPoint(cx,cy,x2,y2,deg);
    Pair rpair3 = rotateDPoint(cx,cy,x3,y3,deg);
    //if (!checkPair(rpair1) || !checkPair(rpair2) || !checkPair(rpair3)) return;

    //drawLSeg(x1,y1,x2,y2);
    drawLSeg(rpair1.x,rpair1.y,rpair2.x,rpair2.y);
    //drawLSeg(x1,y1,x3,y3);
    drawLSeg(rpair1.x,rpair1.y,rpair3.x,rpair3.y);
    //drawLSeg(x2,y2,x3,y3);
    drawLSeg(rpair2.x,rpair2.y,rpair3.x,rpair3.y);
}
