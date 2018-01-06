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
        if(i >= h-a && i <= h+a && checkPair(i,y)) addch('0');

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
        if(i >= h-a && i <= h+a && checkPair(i,y)) addch('0');

    }
}
