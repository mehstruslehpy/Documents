#include "common.h"
#include "SimpsonRule.h"
using namespace std;
double simpsonRule(double* x, double* y, unsigned int n)
{
    return (2.0*midpointRiemannSum(x,y,n)+trapezoidRule(x,y,n))/3.0;
}
double simpsonRuleF(double a, double b, unsigned int n, double (*fx)(double x))
{
    if (n%2!=0)
    {
        cout << "ERROR: simpsons rule requires n be divisible by 2" << endl;
        cout << "ERROR: computing as average of midpoint and trapezoid rule instead" << endl;
        return (2.0*midpointRiemannSumF(a,b,n,fx)+trapezoidRuleF(a,b,n,fx))/3.0;
    }
    double accum = 0;
    double deltax = (b-a)/double(n);

    //cout << "DEBUG:" << accum << endl;
    accum += fx(a);
    //cout << "DEBUG:" << accum << endl;
    accum += fx(b);
    //cout << "DEBUG:" << accum << endl;
    //x_1, x_3, x_5, ...
    for (unsigned int i = 1; i <= n-1; i+=2)
    {
        accum += 4*fx(a+i*deltax);
    }
    //x_2, x_4, x_6, ...
    for (unsigned int i = 2; i <= n-1; i+=2)
    {
        accum += 2*fx(a+i*deltax);
    }

    accum *= deltax/3.0;
    return accum;
}
