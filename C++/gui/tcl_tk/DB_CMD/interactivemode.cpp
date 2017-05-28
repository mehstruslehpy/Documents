#include "definitions.h"

using namespace std;

///interactive mode definition
int interactiveMode()
{
    int SIZE = 0;                       ///this will hold the amount of entries in the database array
    string FILE_NAME = "database.txt"; ///the file name initialized to a default value
    fstream file;           ///the file pointer/fstream object
    Person* database = NULL; ///the data structure that the file will be read into
    string choice;  ///the users menu choice
    int index = 0;  ///an all purpose index to refer to an element in the database
    int lastSort = -1;   ///this will tell us the last sort performed for later
    bool wasRead = false;
    cout << "Would you like to specify a database file? [y/n] ";
    getline(cin, choice);
    if (toupper(choice.at(0)) == 'Y' )
    {
        cout << "Choose a filename for the new database: " << endl;
        getline(cin, choice);
        FILE_NAME = choice;
    }
    else
    {
        cout << "Proceeding with defaults" << endl;
    }
    choice = "";

    cout << "Welcome to my address book! :]" << endl;
    do
    {
        printMenu();
        cout << "> ";
        getline(cin,choice);
        switch (choice.at(0))
        {
        case 'a':
        case 'A':
            ///a hack to prevent from altering the database without first running the read command..
            if(!wasRead)
            {
                cout << "No database loaded, please read from the disk first." << endl;
                cout << "or select w/W to create a new database file." << endl;
                break;
            }
            ///add an entry to the file
            addEntry(file, FILE_NAME, SIZE);
            ///clear any old memory
            if (database != NULL)
            {
                delete [] database;
            }
            ///read the file into memory
            database = readDb(file, FILE_NAME);
            ///update the size of the array of people
            SIZE = database[0].db_size;
            break;
        case 'r':
        case 'R':
            ///read a database
            ///clear any old memory
            if (database != NULL)
            {
                delete [] database;
            }
            ///read the file into memory
            database = readDb(file, FILE_NAME);
            if(database != NULL)
            {
                ///update the size of the array of people
                SIZE = database[0].db_size;
                wasRead = true;
            }
            cout << "Writing backup to " << FILE_NAME + ".bak" << endl;
            writeDatabase(file,(FILE_NAME+".bak"),database,SIZE);
            break;
        case 'd':
        case 'D':
            if(!wasRead)
            {
                cout << "No database loaded, please read from the disk first." << endl;
                cout << "or select w/W to create a new database file." << endl;
                break;
            }
            ///dump the database
            dumpEntries(database, SIZE);
            break;
        case 'p':
        case 'P':
            if(!wasRead)
            {
                cout << "No database loaded, please read from the disk first." << endl;
                cout << "or select w/W to create a new database file." << endl;
                break;
            }
            index = 0;
            cout << "Enter the index of the person you would like to print: ";
            cin >> index;
            printPerson(database, index);
            index = 0;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cin.clear();
            break;
        case 's':
        case 'S':
            if(!wasRead)
            {
                cout << "No database loaded, please read from the disk first." << endl;
                cout << "or select w/W to create a new database file." << endl;
                break;
            }
            sortPerson(file, FILE_NAME, database,lastSort,SIZE,-1);
            writeDatabase(file,FILE_NAME,database,SIZE);
            database = readDb(file, FILE_NAME);
            dumpEntries(database, SIZE);
            break;
        case 'f':
        case 'F':
            if(!wasRead)
            {
                cout << "No database loaded, please read from the disk first." << endl;
                cout << "or select w/W to create a new database file." << endl;
                break;
            }
            cout << "Last sort: " << lastSort << endl;
            index = findPerson(database,lastSort,SIZE);
            if (index != -1)
            {
                cout << "Found at index: " << index << endl;
                printPerson(database,index);
            }
            else
            {
                cout << "Your entry was not found! :O" << endl;
            }
            index = 0;
            break;
        case 'w':
        case 'W':
            cout << "Writing current state of database to disk:" << endl;
            writeDatabase(file,FILE_NAME,database,SIZE);
            wasRead = true;
        case 'Q':
        case 'q':
            break;
        default:
            cout << "I don't know what that means.." << endl;
        }
    }
    while (toupper(choice.at(0))!= 'Q');

    if(wasRead)
    {
        cout << "Writing all changes back to the disk." << endl;
        writeDatabase(file,FILE_NAME,database,SIZE);
    }

    cout << "Goodbye :[" << endl;
    ///clean up
    if (database != NULL)
    {
        delete [] database;
    }
    return 0;
}
