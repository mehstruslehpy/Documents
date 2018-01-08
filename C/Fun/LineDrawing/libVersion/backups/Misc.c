//this file will be for collecting things not suitable for their own separate file
#include "Shapes.h"

//Some of these might be better as macros or using inline rather than normal functions
void drawSinglePoint(double x, double y)
{
    if(!checkPoint(x,y)) return;
    move(y,x);
    addch('0');
}
bool checkPoint(double x,double y)
{
    if (y >= 0 && y <= ROWBOUND &&
            x >= 0 && x <= COLBOUND) return true;

    return false;
}
bool checkPair(Pair p)
{
    return checkPoint(p.x,p.y);
}
//the midpoint formula
Pair midPoint(double x1, double y1, double x2, double y2)
{
    return (Pair) {
        .x=(x1+x2)/2, .y=(y1+y2)/2
    };
}
//the distance formula
double distance(double x1, double x2, double y1, double y2)
{
    double xpart = (x1>x2)?(x1-x2)/2:(x2-x1)/2;
    double ypart = (y1>y2)?(y1-y2)/2:(y2-y1)/2;

    return sqrt(xpart*xpart+ypart*ypart);
}
//convert a degree number to a radian number
double degToRad(double deg)
{
    return deg*(M_PI/180);
}
//convert a radian number to a degree number
double radToDeg(double rad)
{
    return rad*(180/M_PI);
}
//Rotate (x,y) about the center point (cx,cy) by rad radians
Pair rotateRPoint(double cx, double cy, double x,double y, double rad)
{
    //find the new rotated x and y
    double rotx = cos(rad) * (x - cx) - sin(rad) * (y - cy) + cx;
    double roty = sin(rad) * (x - cx) + cos(rad) * (y - cy) + cy;
    return (Pair) {
        .x=rotx, .y=roty
    };
}
//Rotate (x1,y1) about the center point (cx,cy) by deg degrees
Pair rotateDPoint(double cx, double cy, double x,double y, double deg)
{
    return rotateRPoint(cx,cy,x,y,degToRad(deg));
}
//translate a point (x,y) by (tx,ty)
Pair xlatPoint(double tx, double ty, double x, double y)
{
    return (Pair) {
        .x=tx+x, .y=ty+y
    };
}
//draw a pair
void drawPair(Pair p)
{
    drawSinglePoint(p.x,p.y);
}
