#ifndef _SIMPSONRULE_H
#define _SIMPSONRULE_H
#include "common.h"
#include "TrapezoidRule.h"
#include "MidpointRiemannSum.h"
double simpsonRule(double* x, double* y, unsigned int n);
/** Calculate a the numerical approx with the simpson rule using the given
*	function fx over [a,b] divided into n partitions
*	@param a the start of the interval [a,b]
*	@param b the end of the interval [a,b]
*	@param n the partition count
*	@return the left riemann sum from [a,b] divided into n partitions
*/
double simpsonRuleF(double a, double b, unsigned int n, double (*fx)(double x));
#endif
