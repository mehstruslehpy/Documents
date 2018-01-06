#include "Shapes.h"
void drawQuadrilateral(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
    if (!checkPoint(x1,y1) || !checkPoint(x2,y2) || !checkPoint(x2,y2) || !checkPoint(x4,y4)) return;
    drawLSeg(x1,y1,x2,y2);
    //drawLSeg(x2,y2,x1,y1);

    drawLSeg(x1,y1,x3,y3);
    //drawLSeg(x3,y3,x1,y1);

    drawLSeg(x2,y2,x4,y4);
    //drawLSeg(x4,y4,x2,y2);

    drawLSeg(x3,y3,x4,y4);
    //drawLSeg(x4,y4,x3,y3);

    //diagonals
    drawLSeg(x1,y1,x4,y4);
    //drawLSeg(x4,y4,x1,y1);

    drawLSeg(x2,y2,x3,y3);
    //drawLSeg(x3,y3,x2,y2);
}
