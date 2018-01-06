#include "Shapes.h"
void drawTan(double a, double b, double c, double d)
{
    double y = 0;
    //we can calculate row toggles using column values (x-values)

    for (int i = 0; i < COLBOUND; i++)
    {
        y = a*tan(b*(i+c))+d;
        if (checkPoint(i,y))
        {
            move( y, i);	//point (x, a*sin(b*(x+c))+d)
            addch('0');
        }
    }
}
