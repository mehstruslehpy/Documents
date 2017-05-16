#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#define MAX_INPUT_LENGTH numeric_limits<streamsize>::max()  ///the same thing I've been using on almost every project

using namespace std;

///I've seen things done like this elsewhere..
enum {ERROR, ROCK, PAPER, SCISSORS};

///set up some numbers for ranges to use in random number generation
///these are only safe because they are global constants
const int MIN_VALUE = 1;
const int MAX_VALUE = 3;

///from your spec
int getUserChoice(); ///print menu to ask user choice and return as int
int getComputerChoice(); ///generate random computer choice and return as int
void determineWinner(int, int); ///compare the two choices and print the winner (or tie)
void displayChoice(int); ///Print rock, paper, or scissors depending on the int parameter. Use to print the player or the computer's choice.

int main()
{
    ///seed the random number generator with the current time for the computers choices
    unsigned seed = time(0);
    srand(seed);

    ///variables to hold the choices
    int userChoice = 2;
    int compChoice = 3;

    while (1)
    {
        ///get the initial choices
        userChoice = getUserChoice();

        ///if the user chose to exit we will print a goodbye message break out of the loop
        ///you could break out in a number of spots but here seems fairly straightforward
        if (userChoice == 4)
        {
            cout << "**Goodbye**\n";
            break;
        }

        compChoice = getComputerChoice();

        ///display user choice
        cout << "You chose ";
        displayChoice(userChoice);

        ///display computer choice
        cout << " and the computer chose ";
        displayChoice(compChoice);
        cout << "." << endl;

        ///determine a winner
        determineWinner(userChoice, compChoice);
    }
    return 0;
}

int getUserChoice()
{
    ///generate a menu
    cout << "Please make a selection:\n1 -> choose rock\n2 -> choose paper\n3 -> choose scissors\n4 -> quit game\nCHOOSE: ";
    int temp;

    ///take the users input
    cin >> temp;

    ///this is from the input wrapper in the geometry calculator
    ///it seems to work well as an input validator
    cin.ignore(MAX_INPUT_LENGTH, '\n');
    while (temp < 1 || temp > 4 || cin.fail())
    {
        if (cin.fail()) //same as earlier
        {
            cout << "ERROR: EXPECTED A NUMBER\nPlease try again: ";
            cin.clear();
            cin.ignore(MAX_INPUT_LENGTH, '\n');
        }
        else
        {
            cout << "ERROR: input value not in range.\nPlease try again: ";
        }

        cin >> temp;
        cin.ignore(MAX_INPUT_LENGTH, '\n');
    }

    return temp;
}
int getComputerChoice()
{
    ///return a random number from 1 to 3 to signify the computers choice
    return ((rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE);
}
void determineWinner(int user, int comp)
{
    ///brute forcing this might not be the most efficient
    ///but it's fairly readable and simple
    ///basically we check each case the user can enter and spit out text
    ///based on what the computer entered in relation to the users choice
    switch (user)
    {
    case ROCK:
        if (comp == PAPER)
        {
            cout << "You lose!" << endl;
            return;
        }
        else if (comp == ROCK)
        {
            cout << "You tied!" << endl;
            return;
        }
        else
        {
            cout << "You win!" << endl;
            return;
        }
    case PAPER:
        if (comp == PAPER)
        {
            cout << "You tied!" << endl;
            return;
        }
        else if (comp == ROCK)
        {
            cout << "You win!" << endl;
            return;
        }
        else
        {
            cout << "You lose!" << endl;
            return;
        }
    case SCISSORS:
        if (comp == PAPER)
        {
            cout << "You win!" << endl;
            return;
        }
        else if (comp == ROCK)
        {
            cout << "You lose!" << endl;
            return;
        }
        else
        {
            cout << "You tied!" << endl;
            return;
        }
    }
}

///our enums make this more descriptive
void displayChoice(int choice)
{
    ///choose and print an output string
    if (choice == ROCK)
    {
        cout << "rock";
    }
    else if (choice == PAPER)
    {
        cout << "paper";
    }
    else if (choice == SCISSORS)
    {
        cout << "scissors";
    }
    else
    {
        cout << "\nERROR UNEXPECTED VALUE FOR CHOICE: " << choice << endl;
        ///if we make it here something is wrong so exit
        cout << "\n**Goodbye**";
        exit(0);
    }
}
