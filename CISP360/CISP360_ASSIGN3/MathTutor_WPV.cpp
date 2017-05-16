#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#define MAX_INPUT_LENGTH numeric_limits<streamsize>::max()  //this just looks nice to me

using namespace std;

int main()
{
    ///operands for our expression
    int op1;
    int op2;
    int op3;    ///this will hold the users solution

    ///seed random
    srand(time(0));

    ///set op1 and op2
    op1 = rand();
    op2 = rand();

    ///the example uses three digit operands so lets do something sort of like that too
    op1 = op1 % 999;
    op2 = op2 % 999;

    ///debug outputs
    ///cout << "OP1: " << op1 << " OP2: " << op2 << endl;

    ///user input and validation
    cout << "What is: " << op1 << " + " << op2 << " = ?\n";
    cin >> op3;
    cin.ignore(MAX_INPUT_LENGTH, '\n');

///if you felt like giving multiple chances
///    while (op3 != (op1 + op2))
///    {
///        cout << "Incorrect, please try again!\n";
///       cout << "What is: " << op1 << " + " << op2 << " = ?\n";
///        cin >> op3;
///        cin.ignore(MAX_INPUT_LENGTH, '\n');
///    }


    if (op3 != (op1 + op2))
    {
        cout << "That is incorrect. The correct answer was: " << (op1 + op2) << endl;
    }
    else
    {
        cout << "CORRECT! Good job.\n";
    }


    cout << "**press enter to quit**\n";
    cin.get();
    return 0;
}
