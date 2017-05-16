#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>
#define MAX_INPUT_LENGTH numeric_limits<streamsize>::max() //copy paste from my prev assignments

using namespace std;

int game();

int main()
{
    char yesNo = '1';

    game();

    cout << "Would you like to play again?[y/n] " << endl;
    cin >> yesNo;

    while (yesNo == 'y' || yesNo == 'Y')
    {
        game();
        cout << "Would you like to play again?[y/n] ";
        cin >> yesNo;
    }
    cout << "Goodbye!\n";
}

int game()
{
    //seed random number gen
    srand(time(0));
    int number = rand() % 50 + 1;
    int input;
    int guesses = 0;
    //debug
    //cout << "RANDOM NUMBER: " <<number << endl;

    cout << "I'm thinking of a number between 1 and 50\nWhat do you guess: ";
    cin >> input;
    guesses++;
    if (cin.fail()) //check if cin failed because of a char/string input
    {
        cout << "\nERROR: EXPECTED A NUMBER\n\nPlease try again\n"; //print an error message
        cin.clear();                                                //clear the failure
        cin.ignore(MAX_INPUT_LENGTH, '\n');      //I think I need this to discard newlines left by the string in the input buffer?
    }
    while (input != number)
    {
        if (input > number)
            cout << "TOO HIGH" << endl;
        if (input < number)
            cout << "TOO LOW" << endl;
        cout << "Try another guess: ";
        cin >> input;
        if (cin.fail()) //check if cin failed because of a char/string input
        {
            cout << "\nERROR: EXPECTED A NUMBER\n\nPlease try again\n"; //print an error message
            cin.clear();                                                //clear the failure
            cin.ignore(MAX_INPUT_LENGTH, '\n');      //I think I need this to discard newlines left by the string in the input buffer?
        }
        guesses++;
    }
    cout << "Good job that took you: " << guesses << " guesses\n";
    return 0;
}
