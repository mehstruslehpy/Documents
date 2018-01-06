/*! \file Shapes.h
*
*	This file contains the functions to use with ncurses.
*/
#ifndef NSHAPES_MEH
#define NSHAPES_MEH

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

//feel free to change these to match your hardware
/** \brief ROWBOUND The Row Bounds of the screen
*
*	This is used in the included functions to limit the screen space being drawn to
*/
static const double ROWBOUND = 42;
/** \brief COLBOUND The Column Bounds of the screen
*
*	This is used in the included functions to limit the screen space being drawn to
*/
static const double COLBOUND = 100;

/** Draw a Circle via the equation: \f$ (x-h)^2+(y-k)^2=r^2 \f$
*		@param r is the radius
*		@param h is the x coordinate of the center
*		@param k is the y coordinate of the center
*/
void drawCircle(double r, double h, double k);

/** Draw an Ellipse via the equation: \f$ \frac{(x-h)^2}{a^2}+\frac{(y-k)^2}{b^2}=1 \f$
*		@param h is the x coordinate of the center
*		@param k is the y coordinate of the center
*		@param a is the width of the ellipse
*		@param b is the height of the ellipse
*/
void drawEllipse(double a, double b, double h, double k);

/** Draw a Line via the equation: \f$ y=mx+b \f$
*		@param m is the slope
*		@param b is the y intercept
*/
void drawLine(double m, double b);

/** Draw a Rectangle
*		@param x is the top left corners x coordinate
*		@param y is the top left corners y coordinate
*		@param l is the length
*		@param h is the height
*/
void drawRect(double x, double y, double l, double h);

/** Draw a Line Segment through two points
*		@param x_1 the first points x coordinate
*		@param y_1 the first points y coordinate
*		@param x_2 the second points x coordinate
*		@param y_2 the second points y coordinate
*/
void drawLSeg(double x_1, double y_1, double x_2, double y_2);

/** Fill in a non-vertical Line Segment: this is a utility function for drawLSeg()
*		@param x_1 this is used for determining the length to draw in the x direction
*		@param x_2 see above
*		@param y_1 this is needed for the point slope equation of a line
*		@param m   this is needed for the slope equation of a line
*/
void fillLine(double x_1, double x_2, double y_1, double m);

/** Fill in a vertical Line Segment: this is also a utility function for drawLSeg()
*		@param x_1 a vertical between two points has the same starting and ending x coordinate
*		@param y_1 is needed to determine the length to fill and where to fill
*		@param y_2 same as above
*/
void fillVert(double x_1, double y_1, double y_2);

/** Draw a Square: this works the same as drawRect() but only needs one length since all sides of a square are the same length
*		@param x the x coordinate of the top left corner
*		@param y the y coordinate of the top left corner
*/
void drawSqr(double x, double y, double l);

/** Check if the given (x,y) point is within the bounds of the screen
*		@param x the x coordinate
*		@param y the y coordinate
*		@return true if the pair is within the (inclusive) interval [0,ROWBOUND] and [0,COLBOUND] false if not
*/
bool checkPair(double x,double y);

/** Draw a Triangle: using the three specified vertices
*		@param x1 x coordinate for vertex 1
*		@param y1 y coordinate for vertex 1
*		@param x2 x coordinate for vertex 2
*		@param y2 y coordinate for vertex 2
*		@param x3 x coordinate for vertex 3
*		@param y3 y coordinate for vertex 3
*/
void drawTri(double x1, double y1, double x2, double y2, double x3, double y3);

/** Draw a Sine Wave: for the equation \f$ y=asin(b(x+c)+d) \f$
*		@param a amplitude (vertical stretch)
*		@param b frequency (horizontal stretch)
*		@param c phase shift (horizontal shift)
*		@param d vertical shift
*/
void drawSine(double a, double b, double c, double d);

/** Draw a Cosecant: for the equation \f$ y=a\frac{1}{sin(b(x+c))}+d \f$
*		@param a amplitude (vertical stretch)
*		@param b frequency (horizontal stretch)
*		@param c phase shift (horizontal shift)
*		@param d vertical shift
*
*		Due to the vertical asymptotes in a Cosecant and issues in drawing near vertical lines in this library these often don't look very pretty
*/
void drawCosecant(double a, double b, double c, double d);

/** Draw a single point given an x and a y if within the bounds of the screen
*		@param x the x coordinate to draw
*		@param y the y coordinate to draw
*/
void drawSinglePoint(double x, double y);

/** Draw a Quadratic using the vertex form: the equation \f$ y=a(x-h)^2+k \f$
*		@param a the horizontal stretch
*		@param h the x coodinate of the vertex
*		@param k the y coodinate of the vertex
*/
void drawParab(double a, double h, double k);

/** Draw a Quadratic using the standard form: \f$ y=ax^2+bx+c \f$
*		@param a the first coefficient in the standard form
*		@param a the second coefficient in the standard form
*		@param a the third coefficient in the standard form
*/
void drawQuad(double a, double b, double c);

#endif
