#include "common.h"
#include "TrapezoidRule.h"
using namespace std;
/* Calculate a Trapezoidal Riemann Sum on the two arrays given, uses every element*/
double trapezoidRule(double* x, double* y, unsigned int n)
{
    double accum = 0;
    double h = 0;
    double a = 0;
    double b = 0;

    for (unsigned int i = 0; i < n; i++)
    {
        h = x[i+1]-x[i];
        a = y[i];
        b = y[i+1];
        accum += h*(a+b)*.5;
    }
    return accum;
}
//TODO: fix this
/* Calculate a Trapezoidal Riemann Sum using the given function fx over [a,b] divided into n partitions*/
double trapezoidRuleF(double a, double b, unsigned int n, double (*fx)(double x))
{
    double accum = 0;
    double deltax = (b-a)/n;

    accum += 0.5*fx(a);
    accum += 0.5*fx(b);
    for (unsigned int k = 1; k <= n; k++)
    {
        accum += fx(a+k*deltax);
    }
    accum *= deltax;
    return accum;
}
