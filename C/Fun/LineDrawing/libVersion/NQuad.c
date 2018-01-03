#include "Shapes.h"
void drawQuad(double a, double b, double c)
{
    double y = 0;
    for (int i = 0; i < COLBOUND; i++)
    {
        y = a*i*i+b*i+c;

        if (i > COLBOUND)
        {
            break;
        }
        if ( y > ROWBOUND)
        {
            break;
        }

        move( y, i);	//point (x, ax^2+bx+c)
        addch('0');

    }
}
