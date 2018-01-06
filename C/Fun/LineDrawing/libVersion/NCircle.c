#include "Shapes.h"
void drawCircle(double r, double h, double k)
{
    int y = 0;

    //upper half
    for (int i = 0; i < COLBOUND; i++)
    {
        y = sqrt(pow(r,2)-pow((i-h),2))+k;
        if (i > COLBOUND || y > ROWBOUND)
        {
            break;
        }

        move( y, i);
        if(i >= h-r && i <= h+r && checkPoint(i,y)) addch('0');

    }
    //lower half
    for (int i = 0; i < COLBOUND; i++)
    {
        y = -sqrt(pow(r,2)-pow((i-h),2))+k;
        if (i > COLBOUND || y > ROWBOUND)
        {
            break;
        }

        move( y, i);
        if(i >= h-r && i <= h+r && checkPoint(i,y)) addch('0');

    }
}
