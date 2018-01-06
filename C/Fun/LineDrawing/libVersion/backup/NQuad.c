#include "Shapes.h"
void drawQuad(double a, double b, double c)
{
    double y = 0;
    for (int i = 0; i < COLBOUND; i++)
    {
        y = a*i*i+b*i+c;

        if (checkPair(i,y))
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

        if (checkPair(i,y))
        {
            move( y, i);
            addch('0');
        }
    }
}
