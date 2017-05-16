#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
    double annualRate;
    double monthlyRate; //we could just do these in one variable
    double payment;
    int numPay;     //we don't need a rational number for this
    double loanAmt;
    double temp1;
    double temp2;

    //ask for input
    cout << "Enter your annual interest rate: " << endl;
    cin >> annualRate;
    monthlyRate = annualRate / 12.0;    //get monthly rate
    monthlyRate = monthlyRate / 100.0;  //convert to decimal form
    cout << "Enter the number of payments: " << endl;
    cin >> numPay;
    cout << "Enter the amount of your loan: " << endl;
    cin >> loanAmt;

    /* equation from internet
    source: https://www.vertex42.com/ExcelArticles/Images/Amortization-Calculation.gif
    A = P * (r(1+r)^n) / (((1+r)^n) -1) //kinda like this..
    */

    temp1 = monthlyRate * pow((monthlyRate + 1), numPay);   //numerator
    temp2 = pow((1.0 + monthlyRate), numPay) - 1 ;          //denominator
    payment = loanAmt * temp1 / temp2;

    cout << showpoint << setprecision(2) << fixed;   //look pretty etc
    cout << "Loan Amount: $ " << loanAmt << endl;
    cout << "Monthly Interest Rate: " << monthlyRate * 100 << "%" << endl;
    cout << "Number of Payments: " << numPay << endl;
    cout << "Monthly Payment: $ " << payment << endl;
    cout << "Amount Paid Back: $ " << payment * numPay << endl;
    cout << "Interest Paid: $ " << (payment * numPay) - loanAmt << endl;
}
