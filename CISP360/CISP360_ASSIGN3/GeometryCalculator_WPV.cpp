#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#define MAX_INPUT_LENGTH numeric_limits<streamsize>::max()  ///this just looks nice to me
#define PI 3.1415926535897932384626433832795    ///pi to a ridiculous amount of digits

using namespace std;

///this will make main look nicer
int printSelections();
int areaRect();
int areaCircle();
int areaTriangle();

///TODO: make this an infinite loop..
///      don't accept negatives for geometric calculations..
int main()
{
    ///variable for the users choice of calculations
    int selection;


    printSelections();
    cin >> selection;
    cin.ignore(MAX_INPUT_LENGTH, '\n');


    while (selection != 4)
    {
        ///validating here makes the most sense to me now
        ///you could validate before the outer while and validate at the end of the inside of the outer while instead too...
        while (!(selection >= 1 && selection <= 4))
        {
            cout << "\nINVALID SELECTION! Please try again\n";
            printSelections();
            cin >> selection;
            cin.ignore(MAX_INPUT_LENGTH, '\n');
        }

        ///perform the users selected operation
        switch (selection)
        {
        case 1: ///this will need to be revised to take an input value r
            cout << "The area of your circle is: " << areaCircle() << "\n\n";
            break;
        case 2:
            cout << "The area of your rectangle is: " << areaRect() << "\n\n";
            break;
        case 3:
            cout << "The area of your triangle is: " << areaTriangle() << "\n\n";
            break;
        case 4:
            cout << "We don't really need this and you should never see this but it's here just in case\n";
            break;
        }
        printSelections();
        cin >> selection;
        cin.ignore(MAX_INPUT_LENGTH, '\n');

    }
    cout << "Goodbye!" << endl;
    return 0;
}

int printSelections()
{
    cout << "****Geometry Calculator****\n";
    cout << "Please enter a number to choose a calculation to perform.\n";
    cout << "1. Calculate the area of a Circle\n";
    cout << "2. Calculate the area of a Rectangle\n";
    cout << "3. Calculate the area of a Triangle\n";
    cout << "4. Quit\n";
    cout << "TYPE YOUR CHOICE HERE: ";
}

int areaRect()
{
    int length;
    int width;
    cout << "Enter the length of your rectangle: ";
    cin >> length;
    cin.ignore(MAX_INPUT_LENGTH, '\n');
    cout << "Enter the width of your rectangle: ";
    cin >> width;
    cin.ignore(MAX_INPUT_LENGTH, '\n');
    return (length * width);
}

int areaCircle()
{
    int radius;
    cout << "Enter the radius of your circle: ";
    cin >> radius;
    cin.ignore(MAX_INPUT_LENGTH, '\n');
    return (2 * radius * PI);
}

int areaTriangle()
{
    int base;
    int height;
    cout << "Enter the base of your triangle: ";
    cin >> base;
    cin.ignore(MAX_INPUT_LENGTH, '\n');
    cout << "Enter the height of your triangle: ";
    cin >> height;
    cin.ignore(MAX_INPUT_LENGTH, '\n');
    return ((base * height) / 2);
}


