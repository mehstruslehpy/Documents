#include "definitions.h"

using namespace std;

int main()
{
    string choice;
//    int count;  ///count of entries
//    cout << "How many entries in your database?" << endl;
//    cin >> count;
//    cin.ignore(256,'\n');
//
//    Entry* myEntry = initDB(count);
//    printDB(myEntry,count);

    cout << "Wanna write your own program? [y/n]";
    getline(cin, choice);
    if (choice == "y" || choice == "Y")
    {
        dumbFunction();
    }
}
