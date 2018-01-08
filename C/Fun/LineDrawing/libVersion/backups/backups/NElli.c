#include "Shapes.h"
void drawEllipse(double a, double b, double h, double k)
{
    int y = 0;
    //upper half
    for (int i = 0; i < COLBOUND; i++)
    {
        y = sqrt( b*b * ( 1 - pow(i-h,2)/(a*a))) + k;
        if (i > COLBOUND || y > ROWBOUND)
        {
            break;
        }

        move( y, i);
        if(i >= h-a && i <= h+a && checkPoint(i,y)) addch('0');

    }
    //lower half
    for (int i = 0; i < COLBOUND; i++)
    {
        y = -sqrt( b*b * ( 1 - pow(i-h,2)/(a*a))) + k;
        if (i > COLBOUND || y > ROWBOUND)
        {
            break;
        }

        move( y, i);
        if(i >= h-a && i <= h+a && checkPoint(i,y)) addch('0');

    }
}
//rotation version
void drawREllipse(double a, double b, double h, double k, double cx, double cy, double deg)
{
    int y = 0;
    Pair rpair = {.x=0,.y=0};
    //upper half
    for (int i = 0; i < COLBOUND; i++)
    {
        y = sqrt( b*b * ( 1 - pow(i-h,2)/(a*a))) + k;
        if (i > COLBOUND || y > ROWBOUND)
        {
            break;
        }

        //move( y, i);
        rpair = rotateDPoint(cx,cy,i,y,deg);
//        if(i >= h-a && i <= h+a && checkPoint(i,y) && checkPair(rpair))
        if(i >= h-a && i <= h+a && checkPair(rpair))
        {
            //addch('0');
            drawPair(rpair);
        }

    }
    //lower half
    for (int i = 0; i < COLBOUND; i++)
    {
        y = -sqrt( b*b * ( 1 - pow(i-h,2)/(a*a))) + k;
        if (i > COLBOUND || y > ROWBOUND)
        {
            break;
        }

        //move( y, i);
        rpair = rotateDPoint(cx,cy,i,y,deg);
//        if(i >= h-a && i <= h+a && checkPoint(i,y) && checkPair(rpair))
        if(i >= h-a && i <= h+a && checkPair(rpair))
        {
            //addch('0');
            drawPair(rpair);
        }

    }
}
