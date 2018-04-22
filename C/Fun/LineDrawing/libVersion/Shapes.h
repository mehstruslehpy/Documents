/*! \file Shapes.h
*
*	This file contains the functions to use with ncurses. Please note that all functions involving rotations except rotateRPoint()
*	and rotateDPoint() are experimental, use them at your own risk
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
*		@param l the length of each side
*/
void drawSqr(double x, double y, double l);

/** Check if the given (x,y) point is within the bounds of the screen
*		@param x the x coordinate
*		@param y the y coordinate
*		@return true if the coordinates are within the (inclusive) interval [0,ROWBOUND] and [0,COLBOUND] false if not
*/
bool checkPoint(double x,double y);

/** Draw a Triangle: using the three specified vertices
*		@param x1 x coordinate for vertex 1
*		@param y1 y coordinate for vertex 1
*		@param x2 x coordinate for vertex 2
*		@param y2 y coordinate for vertex 2
*		@param x3 x coordinate for vertex 3
*		@param y3 y coordinate for vertex 3
*/
void drawTri(double x1, double y1, double x2, double y2, double x3, double y3);

/** Draw a Quadrilateral: using the four specified vertices
*		@param x1 x coordinate for vertex 1
*		@param y1 y coordinate for vertex 1
*		@param x2 x coordinate for vertex 2
*		@param y2 y coordinate for vertex 2
*		@param x3 x coordinate for vertex 3
*		@param y3 y coordinate for vertex 3
*		@param x4 x coordinate for vertex 4
*		@param y4 y coordinate for vertex 4
*
*		The drawn shape is subject to the same restrictions as the rest of the system, more vertical data means more data loss
*		Since this function results in six lines being drawn the resulting image will often be fairly busy a small quadrilateral
*		look pretty ugly
*/
void drawQuadrilateral(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);

/** Draw a Sine Wave: for the equation \f$ y=asin(b(x+c)+d) \f$
*		@param a amplitude (vertical stretch)
*		@param b frequency (horizontal stretch)
*		@param c phase shift (horizontal shift)
*		@param d vertical shift
*/
void drawSine(double a, double b, double c, double d);

/** Draw a Cosine Wave: for the equation \f$ y=acos(b(x+c)+d) \f$
*		@param a amplitude (vertical stretch)
*		@param b frequency (horizontal stretch)
*		@param c phase shift (horizontal shift)
*		@param d vertical shift
*
*		This function just calls DrawSine(a,b,c+3*M_PI/2,d) to yield the corresponding cosine
*/
void drawCosine(double a, double b, double c, double d);

/** Draw a Tangent function: for the equation \f$ y=atan(b(x+c)+d) \f$
*		@param a amplitude (vertical stretch)
*		@param b frequency (horizontal stretch)
*		@param c phase shift (horizontal shift)
*		@param d vertical shift
*
*		Due to the vertical asymptotes in a Tangent and issues in drawing near vertical lines in this library Tangents often don't look very pretty
*/
void drawTan(double a, double b, double c, double d);


/** Draw a Cosecant: for the equation \f$ y=a\frac{1}{sin(b(x+c))}+d \f$
*		@param a amplitude (vertical stretch)
*		@param b frequency (horizontal stretch)
*		@param c phase shift (horizontal shift)
*		@param d vertical shift
*
*		Due to the vertical asymptotes in a Cosecant and issues in drawing near vertical lines in this library Cosecants often don't look very pretty
*/
void drawCosecant(double a, double b, double c, double d);

/** Draw a single point given an x and a y only draw if the point is within the bounds of the screen
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
*		@param b the second coefficient in the standard form
*		@param c the third coefficient in the standard form
*/
void drawQuad(double a, double b, double c);

/** @struct Pair
*
*	This is not intended to be used as an argument to functions, that sort of interface seems too complicated for this use case.
*
*	@brief Pair is a C-Struct intended to be used to return ordered pairs from functions
*	@var Pair::x
*	the x coordinate of the pair
*	@var Pair::y
*	the y coordinate of the pair
*/
typedef struct Pair
{
    double x;
    double y;
} Pair;

/** Return the midpoint of (x1,y1) and (x2,y2) as a pair
*	@param x1 the x coordinate of (x1,y1)
*	@param y1 the y coordinate of (x1,y1)
*	@param x2 the x coordinate of (x2,y2)
*	@param y2 the y coordinate of (x2,y2)
*	@return a pair representing the midpoint of the given coordinates
*
*	this function uses the formula \f$ ( \frac{x_1+x_2}{2}, \frac{y_1+y_2}{2}) \f$
*/
Pair midPoint(double x1, double y1, double x2, double y2);

/** Returns the distance between (x1,y1) and (x2,y2)
*	@param x1 the x coordinate of (x1,y1)
*	@param y1 the y coordinate of (x1,y1)
*	@param x2 the x coordinate of (x2,y2)
*	@param y2 the y coordinate of (x2,y2)
*	@return a double representing the distance between the given coordinates
*
*	this function uses the formula \f$ \sqrt{(x_2-x_1)^2 + (y_2-y_1)^2} \f$ for \f$ x_2 > x_1 \f$  and \f$ y_2 > y_1 \f$
*/
double distance(double x1, double x2, double y1, double y2);

/** Convert the input deg in degrees to a double in radians
*	@param deg a value in degrees to be converted to a corresponding value in radians
*	@return a double in radians corresponding to the input value
*/
double degToRad(double deg);

/** Convert the input rad in radians to a double in degrees
*	@param rad a value in radians to be converted to a corresponding value in degrees
*	@return a double in degrees corresponding to the input value
*/
double radToDeg(double rad);

/** Returns a Pair corresponding to the rotation of (x,y) by rad in radians about the point (cx,cy)
*	@param cx the x value of the center to be rotated around
*	@param cy the y value of the center to be rotated around
*	@param x the x value of the point to be rotated
*	@param y the y value of the point to be rotated
*	@param rad the angle in radians to rotate
*	@return a pair corresponding to the rotatation of (x,y) around (cx,cy)
*
*	to rotate around the origin do rotateRPoint(0,0,x,y,rad)
*/
Pair rotateRPoint(double cx, double cy, double x,double y, double rad);

/** Returns a Pair corresponding to the rotation of (x,y) by deg in degrees about the point (cx,cy)
*	@param cx the x value of the center to be rotated around
*	@param cy the y value of the center to be rotated around
*	@param x the x value of the point to be rotated
*	@param y the y value of the point to be rotated
*	@param deg the angle in degrees to rotate
*	@return a pair corresponding to the rotatation of (x,y) around (cx,cy)
*
*	to rotate around the origin do rotateDPoint(0,0,x,y,deg)
*	to avoid duplication this is just a wrapper to rotateRPoint() which converts deg to radians
*/
Pair rotateDPoint(double cx, double cy, double x,double y, double deg);

/** Returns a Pair corresponding to (x+tx,x+ty)
*	@param x the x value of the point to be translated
*	@param y the y value of the point to be translated
*	@param tx the translation amount in the x direction
*	@param ty the translation amount in the y direction
*	@return a pair with the values (x+tx,y+ty)
*
*	This function is largely untested at this time
*/
Pair xlatPoint(double tx, double ty, double x, double y);

/** Draws the pair p if p is within the bounds of the screen
*	@param p a pair to draw
*
*	This will only draw if p is within the screen space
*/
void drawPair(Pair p);
/** Check if the given pair is within the bounds of the screen
*		@param p a pair with coordinates to check
*		@return true if the pair contains coordinates within the (inclusive) interval [0,ROWBOUND] and [0,COLBOUND] false if not
*/
bool checkPair(Pair p);

//TODO: test and document for Pairs, midpoint distance and rotation functions
//animated tests are probably the best way to test these

//has some issues with verticality
/** Draw a rotated Sine Wave: for the unrotated equation \f$ y=asin(b(x+c)+d) \f$
*		@param a amplitude (vertical stretch)
*		@param b frequency (horizontal stretch)
*		@param c phase shift (horizontal shift)
*		@param d vertical shift
*		@param cx x value for the center of rotation
*		@param cy y value for the center of rotation
*		@param deg the amount to rotate in degrees
*/
void drawRSine(double a, double b, double c, double d, double cx, double cy, double deg);

//has some issues if the ellipse is not fully on the screen
/** Draw a rotated Ellipse via the unrotated equation: \f$ \frac{(x-h)^2}{a^2}+\frac{(y-k)^2}{b^2}=1 \f$
*		@param h is the x coordinate of the center
*		@param k is the y coordinate of the center
*		@param a is the width of the ellipse
*		@param b is the height of the ellipse
*		@param cx x value for the center of rotation
*		@param cy y value for the center of rotation
*		@param deg the amount to rotate in degrees
*/
void drawREllipse(double a, double b, double h, double k, double cx, double cy, double deg);


//need way better line segment drawing functions to make output look better
/** Draw a rotated Rectangle
*		@param x is the top left corners x coordinate
*		@param y is the top left corners y coordinate
*		@param l is the length
*		@param h is the height
*		@param cx x value for the center of rotation
*		@param cy y value for the center of rotation
*		@param deg the amount to rotate in degrees
*/
void drawRRect(double x, double y, double l, double h, double cx, double cy, double deg);

//same as RRect
/** Draw a rotated Square: this works the same as drawRRect() but only needs one length since all sides of a square are the same length
*		@param x the x coordinate of the top left corner
*		@param y the y coordinate of the top left corner
*		@param l the length of each side
*		@param cx x value for the center of rotation
*		@param cy y value for the center of rotation
*		@param deg the amount to rotate in degrees
*/
void drawRSqr(double x, double y, double l, double cx, double cy, double deg);

/** Draw a rotated Triangle: using the three specified vertices
*		@param x1 x coordinate for vertex 1
*		@param y1 y coordinate for vertex 1
*		@param x2 x coordinate for vertex 2
*		@param y2 y coordinate for vertex 2
*		@param x3 x coordinate for vertex 3
*		@param y3 y coordinate for vertex 3
*		@param cx x value for the center of rotation
*		@param cy y value for the center of rotation
*		@param deg the amount to rotate in degrees
*/
void drawRTri(double x1, double y1, double x2, double y2, double x3, double y3, double cx, double cy, double deg);

//this is a really ugly function signature
//but it seems to work I might remove this later
/** Draw a rotated Quadrilateral: using the four specified vertices (prerotation)
*		@param x1 x coordinate for vertex 1
*		@param y1 y coordinate for vertex 1
*		@param x2 x coordinate for vertex 2
*		@param y2 y coordinate for vertex 2
*		@param x3 x coordinate for vertex 3
*		@param y3 y coordinate for vertex 3
*		@param x4 x coordinate for vertex 4
*		@param y4 y coordinate for vertex 4
*		@param cx x value for the center of rotation
*		@param cy y value for the center of rotation
*		@param deg the amount to rotate in degrees
*
*		Same as the previous drawQuadrilateral
*/
void drawRQuadrilateral(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, double cx, double cy, double deg);

/** Draw a rotated Cosine Wave: for the unrotated equation \f$ y=acos(b(x+c)+d) \f$
*		@param a amplitude (vertical stretch)
*		@param b frequency (horizontal stretch)
*		@param c phase shift (horizontal shift)
*		@param d vertical shift
*		@param cx x value for the center of rotation
*		@param cy y value for the center of rotation
*		@param deg the amount to rotate in degrees
*
*		as before this is a wrapper to drawRSine()
*/
void drawRCosine(double a, double b, double c, double d, double cx, double cy, double deg);

/** Draw a rotated Tangent function: for the unrotated equation \f$ y=atan(b(x+c)+d) \f$
*		@param a amplitude (vertical stretch)
*		@param b frequency (horizontal stretch)
*		@param c phase shift (horizontal shift)
*		@param d vertical shift
*		@param cx x value for the center of rotation
*		@param cy y value for the center of rotation
*		@param deg the amount to rotate in degrees
*/
void drawRTan(double a, double b, double c, double d, double cx, double cy, double deg);

/** Draw a rotated Cosecant: for the unrotated equation \f$ y=a\frac{1}{sin(b(x+c))}+d \f$
*		@param a amplitude (vertical stretch)
*		@param b frequency (horizontal stretch)
*		@param c phase shift (horizontal shift)
*		@param d vertical shift
*		@param cx x value for the center of rotation
*		@param cy y value for the center of rotation
*		@param deg the amount to rotate in degrees
*/
void drawRCosecant(double a, double b, double c, double d,double cx, double cy, double deg);

/** Draw a rotated Quadratic using the vertex form: using the unrotated equation \f$ y=a(x-h)^2+k \f$
*		@param a the horizontal stretch
*		@param h the x coodinate of the vertex
*		@param k the y coodinate of the vertex
*		@param cx x value for the center of rotation
*		@param cy y value for the center of rotation
*		@param deg the amount to rotate in degrees
*/
void drawRParab(double a, double h, double k, double cx, double cy, double deg);

//has issues with the portion normally drawn off the screen in the unrotated version of this function
/** Draw a rotated Quadratic using the unrotated standard form: \f$ y=ax^2+bx+c \f$
*		@param a the first coefficient in the standard form
*		@param b the second coefficient in the standard form
*		@param c the third coefficient in the standard form
*		@param cx x value for the center of rotation
*		@param cy y value for the center of rotation
*		@param deg the amount to rotate in degrees
*/
void drawRQuad(double a, double b, double c, double cx, double cy, double deg);
#endif
