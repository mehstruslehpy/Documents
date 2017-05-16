#include <iostream>
#include <limits>
#define MAX_INPUT_LENGTH numeric_limits<streamsize>::max()  //this just looks nice to me

using namespace std;

int main()
{
    int month;
    int year;

    //enter 1-12 as an integer to signify a month
    cout << "Enter a month (1-12): ";
    cin >> month;
    cin.ignore(MAX_INPUT_LENGTH, '\n'); //ignore everything after the first token

    //validate the month, the month can't be less than 1 or greater than 12
    while ( month < 1 || month > 12)
    {
        cout << "ERROR: INPUT MONTH OUTSIDE OF RANGE\nEnter a month (1-12): ";
        cin >> month;
        cin.ignore(MAX_INPUT_LENGTH, '\n');
    }

    //enter a four digit year as an integer
    cout << "Enter a year: ";
    cin >> year;
    cin.ignore(MAX_INPUT_LENGTH, '\n');

    //validate the year
    //I guess you could interpret the assignment prompt to mean year < 1000 should go here but then I figured cases like this: year == 0001, year == 0029 etc...
    while (year < 0)
    {
        cout << "ERROR: INPUT YEAR TOO SMALL\nEnter a year: ";
        cin >> year;
        cin.ignore(MAX_INPUT_LENGTH, '\n');
    }

    //debug outputs
    //cout << "MONTH: " << month << " YEAR: " << year << endl;

    //determine if the year is a leap year and if the selected month is february if both are true, the user has entered February of a leap year, else just print the normal amount of days
    if (((year % 4 == 0) && (year % 100 != 0)) || ((year % 100 == 0) && (year % 400 == 0)) && month == 2 )
    {
        cout << "February during a leap year has 29 Days\n";
    }
    else
    {
        switch (month)
        {
        case 1:
            cout << "January has 31 days\n";
            break;
        case 2:
            cout << "February has 28 days\n";
            break;
        case 3:
            cout << "March has 31\n";
            break;
        case 4:
            cout << "April has 30\n";
            break;
        case 5:
            cout << "May has 31\n";
            break;
        case 6:
            cout << "June has 30\n";
            break;
        case 7:
            cout << "July has 31\n";
            break;
        case 8:
            cout << "August has 31\n";
            break;
        case 9:
            cout << "September has 30\n";
            break;
        case 10:
            cout << "October has 31\n";
            break;
        case 11:
            cout << "November has 30\n";
            break;
        case 12:
            cout << "December has 31\n";
            break;
        default:
            break;
        }
    }
    return 0;
}
