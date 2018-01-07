#include "Shapes.h"
void drawQuadrilateral(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
    //if (!checkPoint(x1,y1) || !checkPoint(x2,y2) || !checkPoint(x2,y2) || !checkPoint(x4,y4)) return;
    drawLSeg(x1,y1,x2,y2);
    drawLSeg(x1,y1,x3,y3);
    drawLSeg(x2,y2,x4,y4);
    drawLSeg(x3,y3,x4,y4);

    //diagonals
    drawLSeg(x1,y1,x4,y4);
    drawLSeg(x2,y2,x3,y3);
}

//yuck
void drawRQuadrilateral(double x1, double y1,
                        double x2, double y2,
                        double x3, double y3,
                        double x4, double y4,
                        double cx, double cy,
                        double deg)
{
    Pair rpair1 = rotateDPoint(cx,cy,x1,y1,deg);
    Pair rpair2 = rotateDPoint(cx,cy,x2,y2,deg);
    Pair rpair3 = rotateDPoint(cx,cy,x3,y3,deg);
    Pair rpair4 = rotateDPoint(cx,cy,x4,y4,deg);
    //if (!checkPair(rpair1) || !checkPair(rpair2) || !checkPair(rpair3) || !checkPair(rpair4)) return;

    drawLSeg(rpair1.x,rpair1.y,rpair2.x,rpair2.y);
    drawLSeg(rpair1.x,rpair1.y,rpair3.x,rpair3.y);
    drawLSeg(rpair2.x,rpair2.y,rpair4.x,rpair4.y);
    drawLSeg(rpair3.x,rpair3.y,rpair4.x,rpair4.y);

    //diagonals
    drawLSeg(rpair1.x,rpair1.y,rpair4.x,rpair4.y);
    drawLSeg(rpair2.x,rpair2.y,rpair3.x,rpair3.y);
}
