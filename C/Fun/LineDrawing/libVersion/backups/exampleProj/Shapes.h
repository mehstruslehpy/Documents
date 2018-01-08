#ifndef NSHAPES_WPV
#define NSHAPES_WPV

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

/** The Row Bounds of the screen */
#define ROWBOUND 42
/** The Column Bounds of the screen */
#define COLBOUND 42
/** Draw an Circle*/
void drawCircle(double r, double h, double k);
/** Draw an Ellipse*/
void drawEllipse(double a, double b, double h, double k);
/** Draw a Line*/
void drawLine(double m, double b);
/** Draw a Rectangle*/
void drawRect(double x, double y, double l, double h);
/** Draw a Line Segment*/
void drawLSeg(double x_1, double y_1, double x_2, double y_2);
/** Fill in a non-vertical Line Segment*/
void fillLine(double x_1, double x_2, double y_1, double m);
/** Fill in a vertical Line Segment*/
void fillVert(double x_1, double y_1, double y_2);
/** Draw a Square*/
void drawSqr(double x, double y, double l);
/** Check that the given coordinate is within the bounds of the screen*/
bool checkPair(double x,double y);
/** Draw a Triangle */
void drawTri(double x1, double y1, double x2, double y2, double x3, double y3);
/** Draw a Quadratic */
void drawQuad(double a, double b, double c);
/** Draw a Sine Wave */
void drawSine(double a, double b, double c, double d);

#endif
