#include "Shapes.h"
void drawCosecant(double a, double b, double c, double d)
{
    double y = 0;
    //we can calculate row toggles using column values (x-values)

    for (int i = 0; i < COLBOUND; i++)
    {
        y = a*(1/sin(b*(i+c)))+d;
        if (checkPoint(i,y))
        {
            move( y, i);
            addch('0');
        }

    }
}
