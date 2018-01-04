//this file will be for collecting things not suitable for their own separate file
#include "Shapes.h"

//These might be better as macros rather than functions
void drawSinglePoint(double x, double y)
{
    if(!checkPair(x,y)) return;
    move(y,x);
    addch('0');
}
bool checkPair(double x,double y)
{
    if (y >= 0 && y <= ROWBOUND &&
            x >= 0 && x <= COLBOUND) return true;

    return false;
}
