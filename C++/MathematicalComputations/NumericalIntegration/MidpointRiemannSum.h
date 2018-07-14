#ifndef _MIDPOINTRIEMANNSUM_H
#define _MIDPOINTRIEMANNSUM_H
#include "common.h"
#include "TrapezoidRule.h"
//this will effectively function as an alias for the trapezoid rule version of this function
double midpointRiemannSum(double* x, double* y, unsigned int n);
//on discrete arrays of data a midpoint riemann sum is impossible, averaging though two heights is essentially the
//trapezoid rule
/** Calculate a midpoint Riemann Sum using the given function fx over [a,b] divided into n partitions
*	@param a the start of the interval [a,b]
*	@param b the end of the interval [a,b]
*	@param n the partition count
*	@return the left riemann sum from [a,b] divided into n partitions
*/
double midpointRiemannSumF(double a, double b, unsigned int n, double (*fx)(double x));
#endif
