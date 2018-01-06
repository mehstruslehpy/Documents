#include "Shapes.h"
void drawLine(double m, double b)
{
    double y = 0;
    move(0,b);

    for (int i = 0; i < COLBOUND; i++)
    {
        y = m*i + b;
        if (checkPoint(i,y))
        {
            move( y, i);
            addch('0');
        }

    }
}
