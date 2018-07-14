#include "common.h"
#include "MidpointRiemannSum.h"
using namespace std;
double midpointRiemannSum(double* x, double* y, unsigned int n)
{
    return trapezoidRule(x,y,n);
}
/* Calculate a Midpoint Riemann Sum using the given function fx over [a,b] divided into n partitions*/
double midpointRiemannSumF(double a, double b, unsigned int n, double (*fx)(double x))
{
    double accum = 0;
    double xk = 0;
    double deltax = (b-a)/n;

    for (unsigned int k = 1; k <= n; k++)
    {
        xk = a + (k-0.5)*deltax;
        accum += fx(xk) * deltax;
    }

    return accum;
}
