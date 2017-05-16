#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>
#define MAX_INPUT_LENGTH numeric_limits<streamsize>::max() //copy paste from my prev assignments

using namespace std;

int main()
{
    int input;
    int temp;
    cout << "Enter the amount of rows for your triangle[1-20]: ";
    cin >> input;
    while ( !(input >= 1 && input <= 20) || cin.fail())
    {

        if (cin.fail()) //check if cin failed because of a char/string input
        {
            cout << "ERROR: EXPECTED A NUMBER\nPlease try again\n"; //print an error message
            cin.clear();                                                //clear the failure
            cin.ignore(MAX_INPUT_LENGTH, '\n');      //I think I need this to discard newlines left by the string in the input buffer?
        }
        else
        {
            cout << "ERROR: NUMBER OUT OF RANGE\nPlease try again\n";
        }
        cin >> input;
    }
    //if we make it here we can print the triangle
    while (input != 0)  //print the row
    {
        temp = input;
        while (temp != 0)   //print the asterisks
        {
            cout << "*";
            temp = temp - 1;
        }
        cout << endl;
        input = input - 1;
    }
}

