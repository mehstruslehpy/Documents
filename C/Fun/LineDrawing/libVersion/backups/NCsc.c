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
void drawRCosecant(double a, double b, double c, double d, double cx, double cy, double deg)
{
    Pair rpair = {.x=0,.y=0};
    double y = 0;
    for (int i = 0; i < COLBOUND; i++)
    {
        y = a*(1/sin(b*(i+c)))+d;
        rpair = rotateDPoint(cx,cy,i,y,deg);
        if (checkPair(rpair))
        {
            drawPair(rpair);
        }

    }
}
