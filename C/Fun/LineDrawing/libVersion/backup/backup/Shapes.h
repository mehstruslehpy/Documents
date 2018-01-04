#ifndef NSHAPES_MEH
#define NSHAPES_MEH

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

//feel free to change these to match your hardware
/** The Row Bounds of the screen */
//#define ROWBOUND 42
static const double ROWBOUND = 42;
/** The Column Bounds of the screen */
//#define COLBOUND 42
static const double COLBOUND = 42;

/** Draw a Circle
*		:r is the radius
*		:h is the x coordinate of the center
*		:k is the y coordinate of the center
*/
void drawCircle(double r, double h, double k);

/** Draw an Ellipse
*		:h is the x coordinate of the center
*		:k is the y coordinate of the center
*		:a and b are for the height and width
*/
void drawEllipse(double a, double b, double h, double k);

/** Draw a Line
*		:m is the slope
*		:b is the y intercept
*/
void drawLine(double m, double b);

/** Draw a Rectangle
*		:x is the top left corners x coordinate
*		:y is the top left corners y coordinate
*		:l is the length
*		:h is the height
*/
void drawRect(double x, double y, double l, double h);

/** Draw a Line Segment
*		:x1 and y1 is the starting point
*		:x2 and y2 is the ending point
*/
void drawLSeg(double x_1, double y_1, double x_2, double y_2);

/** Fill in a non-vertical Line Segment
*		:this is a utility function for drawLSeg()
*/
void fillLine(double x_1, double x_2, double y_1, double m);

/** Fill in a vertical Line Segment
*		:this is a utility function for drawLSeg()
*/
void fillVert(double x_1, double y_1, double y_2);

/** Draw a Square
*		:the same as drawRect() but you only need one length because this a square
*/
void drawSqr(double x, double y, double l);

/** Check that the given coordinate is within the bounds of the screen*/
bool checkPair(double x,double y);

/** Draw a Triangle
*		:using the three specified vertices
*/
void drawTri(double x1, double y1, double x2, double y2, double x3, double y3);

/** Draw a Sine Wave
*		:for the equation y = a*sin(b(x+c)+d)
*/
void drawSine(double a, double b, double c, double d);

//!!!!!
//TODO: Functions beyond this line are new or modified and new more testing
//!!!!!

/** Draw a single point
*		:Uses the coordinate (x,y) draws the point if it is
*		:within the bounds of the screen
*/
void drawSinglePoint(double x, double y);

/** Draw a Quadratic using the vertex form
*		:for the equation y = a(x-h)^2+k
*		:(h,k) is the coordinate of the vertex
*/
void drawParab(double a, double h, double k);

/** Draw a Quadratic using the standard form
*		:for the equation y = ax^2 + bx + c
*/
void drawQuad(double a, double b, double c);

#endif
