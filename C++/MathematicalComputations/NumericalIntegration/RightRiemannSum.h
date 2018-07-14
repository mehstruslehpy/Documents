#ifndef _RIGHTRIEMANNSUM_H
#define _RIGHTRIEMANNSUM_H
#include "common.h"
/** Calculate a right Riemann Sum on the two arrays given, uses every element
*	@param x a pointer to an array of x values
*	@param y a pointer to an array of y values
*	@param n the count of elements to sum in the arrays, should be one less than the count of elememts in the array
*	@return the right Riemann sum from x_0 to x_n
*/
double rightRiemannSum(double* x, double* y, unsigned int n);
/** Calculate a right Riemann Sum using the given function fx over [a,b] divided into n partitions
*	@param a the start of the interval [a,b]
*	@param b the end of the interval [a,b]
*	@param n the partition count
*	@return the right riemann sum from [a,b] divided into n partitions
*/
double rightRiemannSumF(double a, double b, unsigned int n, double (*fx)(double));
#endif
