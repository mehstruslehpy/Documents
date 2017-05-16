#include <iostream>
#define TAX 0.0675   //this seemed like a good choice for a define statement, it's easy to change if sales tax changes

using namespace std;

int main()
{
    double bill;
    double tipAmt;

    cout << "Enter the cost of your food: ";
    cin >> bill;
    cout << "Enter the percentage you wish to tip: ";
    cin >> tipAmt;
    cout << endl;

    cout << "Meal cost:           " << bill << endl;                      //reiterate the meal cost to user
    cout << "Tax applied to bill: " << (bill * TAX) << endl;              //calculate and print tax
    cout << "Tip applied to bill: " <<  bill * (tipAmt / 100) << endl;    //calculate and print tip
    cout << "__________________________+" << endl;                        //pretty
    cout << "Your total:          " << bill + (bill * TAX) + (bill * (tipAmt / 100)) << endl; //bill+tip+tax
    cout << "*Press enter to quit*" << endl;
    cin.get();  //for some reason on my machine I need this twice to pause
    cin.get();
    return 0;
}
