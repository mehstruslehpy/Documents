#ifndef _LEFTRIEMANNSUM_H
#define _LEFTRIEMANNSUM_H
#include "common.h"
/** Calculate a Left Riemann Sum on the two arrays given, uses every element
*	@param x a pointer to an array of x values
*	@param y a pointer to an array of y values
*	@param n the count of elements to sum in the arrays, should be one less than the count of elememts in the array
*	@return the left Riemann sum from x_0 to x_n
*/
double leftRiemannSum(double* x, double* y, unsigned int n);
/** Calculate a Left Riemann Sum using the given function fx over [a,b] divided into n partitions
*	@param a the start of the interval [a,b]
*	@param b the end of the interval [a,b]
*	@param n the partition count
*	@return the left riemann sum from [a,b] divided into n partitions
*/
double leftRiemannSumF(double a, double b, unsigned int n, double (*fx)(double x));
#endif
