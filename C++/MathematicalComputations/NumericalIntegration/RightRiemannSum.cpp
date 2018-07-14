#include "common.h"
#include "RightRiemannSum.h"
using namespace std;
/* Calculate a Right Riemann Sum on the two arrays given, uses every element*/
double rightRiemannSum(double* x, double* y, unsigned int n)
{
    double accum = 0;
    double rectheight = 0;
    double rectwidth = 0;

    for (unsigned int i = 0; i < n; i++)
    {
        rectheight = y[i+1]; //the right side of every partition
        rectwidth = x[i+1]-x[i]; //the width of the partition
        accum += rectheight*rectwidth;
    }
    return accum;
}
/* Calculate a Right Riemann Sum using the given function fx over [a,b] divided into n partitions*/
double rightRiemannSumF(double a, double b, unsigned int n, double (*fx)(double))
{
    double accum = 0;
    double xk = 0;
    double deltax = (b-a)/n;

    for (unsigned int k = 1; k <= n; k++)
    {
        xk = a + k*deltax;
        accum += fx(xk) * deltax;
    }
    return accum;
}
