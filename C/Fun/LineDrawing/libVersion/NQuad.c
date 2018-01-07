#include "Shapes.h"
void drawQuad(double a, double b, double c)
{
    double y = 0;
    for (int i = 0; i < COLBOUND; i++)
    {
        y = a*i*i+b*i+c;

        if (checkPoint(i,y))
        {
            move( y, i);
            addch('0');
        }
    }
}

//this is the vertex form
//y = a(x-h)^2+k
void drawParab(double a, double h, double k)
{
    double y = 0;
    for (int i = 0; i < COLBOUND; i++)
    {
        y = a*(i-h)*(i-h)+k;

        if (checkPoint(i,y))
        {
            move( y, i);
            addch('0');
        }
    }
}

void drawRQuad(double a, double b, double c, double cx, double cy, double deg)
{
    Pair rpair = {.x=0,.y=0};
    double y = 0;
    for (int i = 0; i < COLBOUND; i++)
    {
        y = a*i*i+b*i+c;
        rpair = rotateDPoint(cx,cy,i,y,deg);
        if (checkPair(rpair))
        {
            drawPair(rpair);
        }
    }
}

//this is the vertex form
//y = a(x-h)^2+k
void drawRParab(double a, double h, double k, double cx, double cy, double deg)
{
    Pair rpair = {.x=0,.y=0};
    double y = 0;
    for (int i = 0; i < COLBOUND; i++)
    {
        y = a*(i-h)*(i-h)+k;
        rpair = rotateDPoint(cx,cy,i,y,deg);
        if (checkPair(rpair))
        {
            drawPair(rpair);
        }
    }
}

