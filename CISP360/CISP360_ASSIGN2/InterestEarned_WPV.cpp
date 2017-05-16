#include <iostream>
#include <math.h>       //need this for pow()
#include <iomanip>

using namespace std;

int main()
{

    double principal;   //the initial balance of the account
    double interest;    //the interest rate in percent
    int numYrs;      //the number of years the deposit was held
    double total = 0;   //the total probably don't need to initialize this
    double temp;

    cout << "Enter the initial balance of your account(the principal): " << endl;
    cin >> principal;
    cout << "Enter the interest rate on your account: " << endl;
    cin >> interest;
    interest = interest / 100;   //convert the input percent interest to a decimal
    cout << "Enter the number of years your deposit was held: " << endl;
    cin >> numYrs;

    /* simple interest equation from the email:
    A = total accrued principal plus interest
    P = principal
    r = interest rate
    t = time period
    A = P * (1 + r)^t
    */

    //calculate the total
    temp = pow(( 1 + interest), numYrs);
    total = principal * temp;

    //real outputs
    cout << showpoint << setprecision(2) << fixed;
    cout << "INTEREST RATE: " << (interest * 100) << "%" << endl;
    cout << "YEARS HELD: " << numYrs << " yrs" << endl;
    cout << "PRINCIPAL: $ " << principal << endl;
    cout << "INTEREST EARNED: $ " << (total - principal) << endl;
    cout << "AMOUNT IN SAVINGS: $ " << total << endl;

    //press enter to quit bits
    cout << "*PRESS ENTER TO EXIT*"<<endl;
    cin.get();
    cin.get();

    return 0;
}
