#include "Shapes.h"
void drawCosine(double a, double b, double c, double d)
{
    drawSine(a,b,c+(3*M_PI/2),d);
}
void drawRCosine(double a, double b, double c, double d, double cx, double cy, double deg)
{
    drawRSine(a,b,c+(3*M_PI/2),d,cx,cy,deg);
}
