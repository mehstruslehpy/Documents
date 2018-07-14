#include <math.h>
#include <iomanip>
#include <float.h> //DBL_MIN and DBL_MAX
#include "common.h"
#include "LeftRiemannSum.h"
#include "MidpointRiemannSum.h"
#include "RightRiemannSum.h"
#include "SimpsonRule.h"
#include "TrapezoidRule.h"

using namespace std;
//some test functions
double weird_e_Func(double x)
{
    return exp(-1*pow(x,2));
}
double weird_e_Func1(double x)
{
    return pow(x,2)*exp(-1*pow(x,2));
}
double lnOfSinx(double x)
{
    return log(sin(x));
}
double weird_e_Func2(double x)
{
	return exp(-2*pow(x,2));
}
double uglyFunc(double x)
{
	return pow(x,7)-3*pow(x,5)-pow(x,2)+7.0/8.0;
}
double uglyFunc2(double x)
{
	return pow(x,2);
}
int main()
{
    //a parabola y =x^2 with six elements
    double x[] = {0,1,2,3,4,5,6};
    double y[] = {0,1,4,9,16,25,36};
    unsigned int n = 6;

    double tx[] = {2,2.5,3,3.5,4};
    double ty[] = {4,6.25,9,12.25,16};
    unsigned int tn = 4;

    double result = 0;

    result = leftRiemannSum(x,y,n);
    cout << "The sum for: x[i]={0,1,2,3,4,5,6}" << endl;
    cout << "             y[i]={0,1,4,9,16,25,36}" << endl;
    cout << "Left Riemann Sum Result: " <<setprecision(30)<< result << endl << endl;

    result = leftRiemannSumF(0,M_PI/2,200,sin);
    cout << "The sum from [0,pi/2] with n=200 of sinx" << endl;
    cout << "Left Riemann Sum Functional Result: " << result << endl<<endl;

    cout << "The sum for: x[i]={0,1,2,3,4,5,6}" << endl;
    cout << "             y[i]={0,1,4,9,16,25,36}" << endl;
    result = rightRiemannSum(x,y,n);
    cout << "Right Riemann Sum Result: " << result << endl<<endl;

    result = rightRiemannSumF(0,M_PI/2.0,200,sin);
    cout << "The sum from [0,pi/2] with n=200 of sinx" << endl;
    cout << "Right Riemann Sum Functional Result: " << result << endl<<endl;

    result = midpointRiemannSumF(0,M_PI/2.0,200,sin);
    cout << "The sum from [0,pi/2] with n=200 of sinx" << endl;
    cout << "Midpoint Riemann Sum Functional Result: " << result << endl<<endl;

    cout << "The sum for tx[i]={2,2.5,3,3.5,4}" << endl;
    cout << "            ty[i]={4,6.25,9,12.25,16}"<< endl;
    result = trapezoidRule(tx,ty,tn);
    cout << "Trapezoid Rule Result: " << result << endl<<endl;

    cout << "The sum for: x[i]={0,1,2,3,4,5,6}" << endl;
    cout << "             y[i]={0,1,4,9,16,25,36}" << endl;
    result = trapezoidRule(x,y,n);
    cout << "Trapezoid Rule Result: " << result << endl<<endl;

    result = trapezoidRuleF(0,M_PI/2,200,sin);
    cout << "The sum from [0,pi/2] with n=200 of sinx" << endl;
    cout << "Trapezoid Rule Functional Result: " << result << endl<<endl;

    cout << endl;
    cout << "For n=512, integral(e^(-x^2),x,0,2) is approx =" << trapezoidRuleF(0,2,512,weird_e_Func) << endl;
    cout << endl;
    cout << "For n=512, integral(e^(-x^2),x,0,4) is approx =" << trapezoidRuleF(0,4,512,weird_e_Func) << endl;
    cout << endl;
    cout << "For n=512, integral(e^(-x^2),x,0,8) is approx =" << trapezoidRuleF(0,8,512,weird_e_Func) << endl;
    cout << endl;
    cout << "For n=512, integral(x^2*e^(-x^2),x,0,8) is approx =" << trapezoidRuleF(0,8,512,weird_e_Func1) << endl;
    cout << endl;
    //cout << "For n=2^24, integral(ln(sin(x)),x,0,pi/2) is approx =" << midpointRiemannSumF(1.0e-100,M_PI/2,static_cast<unsigned int>(pow(2,24)),lnOfSinx)<< endl;
    cout << endl;
    cout << "For n=512, integral(e^(-x^2),x,0,2) is approx =" << simpsonRuleF(0,2,512,weird_e_Func) << endl;
    cout << "For n=220, integral(sinx,x,0,pi/2) is approx =" << simpsonRuleF(0,M_PI/2,220,sin) << endl;
    result = simpsonRule(x,y,n);
    cout << "The sum for: x[i]={0,1,2,3,4,5,6}" << endl;
    cout << "             y[i]={0,1,4,9,16,25,36}" << endl;
    cout << "Simpson Rule Result: " <<setprecision(30)<< result << endl << endl;
    cout << "The sum for tx[i]={2,2.5,3,3.5,4}" << endl;
    cout << "            ty[i]={4,6.25,9,12.25,16}"<< endl;
    result = simpsonRule(tx,ty,tn);
    cout << "Simpson Rule Result: " << result << endl<<endl;

    cout << "Result: " << simpsonRuleF(-1,1,2^20,weird_e_Func2) << endl<<endl;

	cout << "Trapezoid approx:" << endl;
	cout << "\t" << trapezoidRuleF(-1,2,4,uglyFunc) << endl;
	cout << "\t" << trapezoidRuleF(-1,2,8,uglyFunc) << endl;
	cout << "\t" << trapezoidRuleF(-1,2,16,uglyFunc) << endl;
	cout << "\t" << trapezoidRuleF(-1,2,32,uglyFunc) << endl;
	cout << "\t" << trapezoidRuleF(-1,2,64,uglyFunc) << endl;
	cout << "MRS approx:" << endl;
	cout << "\t" << midpointRiemannSumF(-1,2,4,uglyFunc) << endl;
	cout << "\t" << midpointRiemannSumF(-1,2,8,uglyFunc) << endl;
	cout << "\t" << midpointRiemannSumF(-1,2,16,uglyFunc) << endl;
	cout << "\t" << midpointRiemannSumF(-1,2,32,uglyFunc) << endl;
	cout << "\t" << midpointRiemannSumF(-1,2,64,uglyFunc) << endl;

	cout << "T(6):" << trapezoidRuleF(0,3,6,uglyFunc2) << endl;
	cout << "M(6):" << midpointRiemannSumF(0,3,6,uglyFunc2) << endl;
	cout << "T(12):" << trapezoidRuleF(0,3,12,uglyFunc2) << endl;
	cout << "M(12):" << midpointRiemannSumF(0,3,12,uglyFunc2) << endl;

    return 0;
}
