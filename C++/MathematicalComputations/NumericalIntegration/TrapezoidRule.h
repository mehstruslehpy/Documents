#ifndef _TRAPEZOIDRULE_H
#define _TRAPEZOIDRULE_H
#include "common.h"

/** Calculate a Trapezoidal Riemann Sum on the two arrays given, uses every element
*	@param x a pointer to an array of x values
*	@param y a pointer to an array of y values
*	@param n the count of elements to sum in the arrays, should be one less than the count of elememts in the array
*	@return the left Riemann sum from x_0 to x_n
*/
double trapezoidRule(double* x, double* y, unsigned int n);

/** A the closest thing to a midpoint riemann sum on an array of values is the trapezoid rule
*
*/
//const auto& midpointRiemannSum = static_cast<double(*)(double*,double*,unsigned int)>(trapezoidRule);

/** Calculate a Trapezoidal Riemann Sum using the given function fx over [a,b] divided into n partitions
*	@param a the start of the interval [a,b]
*	@param b the end of the interval [a,b]
*	@param n the partition count
*	@return the left riemann sum from [a,b] divided into n partitions
*/
double trapezoidRuleF(double a, double b, unsigned int n, double (*fx)(double x));

#endif
