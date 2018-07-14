#include "common.h"
#include "LeftRiemannSum.h"
using namespace std;
/* Calculate a Left Riemann Sum on the two arrays given, uses every element*/
double leftRiemannSum(double* x, double* y, unsigned int n)
{
    double accum = 0;
    double rectheight = 0;
    double rectwidth = 0;
    for (unsigned int i = 0; i < n; i++)
    {
        //cout << "DEBUG: i=" << i << endl;
        //cout << "DEBUG: i+1=" << i+1 << endl;
        //cout << "DEBUG: \tx[" << i << "]=" << x[i] << endl;
        //cout << "DEBUG: \tx[" << i+1 << "]=" << x[i+1] << endl;
        //cout << "DEBUG: \ty[" << i << "]=" << y[i] << endl;
        rectheight = y[i]; //the left side of every partition
        rectwidth = x[i+1]-x[i]; //the width of the partition
        //cout << "DEBUG: rectheight=" << rectheight << endl;
        //cout << "DEBUG: rectwidth=" << rectwidth << endl;
        accum += rectheight*rectwidth;
        //cout << "DEBUG: accum=" << accum << endl;
    }
    return accum;
}
/* Calculate a Left Riemann Sum using the given function fx over [a,b] divided into n partitions*/
double leftRiemannSumF(double a, double b, unsigned int n, double (*fx)(double x))
{
    double accum = 0;
    double xk = 0;
    double deltax = (b-a)/n;

    for (unsigned int k = 1; k <= n; k++)
    {
        xk = a + (k-1)*deltax;
        accum += fx(xk) * deltax;
    }

    return accum;
}
