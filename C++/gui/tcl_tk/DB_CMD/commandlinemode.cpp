///because this is essentially a mod of the original program the code below is very hacky
///my only intention was to make a semi-usable command line interface that could be utilized
///in bash/bat style scripts
#include "definitions.h"

using namespace std;

void modeSummary();

int commandLineMode(int argc, char *argv[])
{
    int SIZE = 0;                       ///this will hold the amount of entries in the database array
    string FILE_NAME = ""; ///the file name initialized to a default value
    fstream file;           ///the file pointer/fstream object
    Person* database = NULL; ///the data structure that the file will be read into
    bool wasRead = false;

    ///a string to hold various switches corresponding to the individual modes...
    string modeFlag = argv[1];

    ///this first one should have been its own function...
    if ((argv[2] != NULL && modeFlag == "-a") || modeFlag == "-A")
    {
        string name = "";
        int age;
        int personId;
        int rating;
        string phone;
        string address;
        string notes;

        cout << "Append mode" << endl;
		cout << "name: ";
        if(strcmp(argv[2], "-name"))
        {
            cout << "Error no name" << endl;
        }

        ///an iterator
        int i = 2;

        ///read the name
        while ( strcmp(argv[i],"-age") != 0 && argv[i+1] != NULL)
        {
            ///we do not want to read the flags as a name
            if (strcmp(argv[i],"-age") && strcmp(argv[i], "-name"))
            {
                name.append(argv[i]);
                name += " ";    ///keep the spaces
            }
            i++;
        }

        ///read the age
        if (i != 2 && argv[i+1] != NULL)
        {
            cout << name << endl;
//            cout << "age flag is the: " << i << " word" << endl;
            age = atoi(argv[i+1]);
            cout << "age: " << age << endl;
            i += 2; ///jump past the age flag and the age itself
        }
        else
        {
            cout << "Error no or bad age specified" << endl;
        }

        ///read the person id
        if (argv[i] != NULL &&
                argv[i+1] != NULL &&
                strcmp(argv[i], "-pid") == 0 &&
                argv[i+1] != NULL
           )
        {
//            cout << "person-id index:" << i << endl;
            personId= atoi(argv[i+1]);
            cout << "person-id: " << personId << endl;
            i += 2; ///jump past the flag and value
        }
        else
        {
            cout << "Error no or bad person-id specified" << endl;
        }

        ///read the rating
        if (argv[i+1] != NULL &&
                argv[i] != NULL &&
                strcmp(argv[i], "-rating") == 0 &&
                !(atoi(argv[i+1]) < 0) &&
                !(atoi(argv[i+1]) > 10)
           )
        {
//            cout << "rating index:" << i << endl;
            personId= atoi(argv[i+1]);
            cout << "rating: " << personId << endl;
            i += 2; ///jump past the flag and value
        }
        else
        {
            cout << "Error no or bad rating specified" << endl;
        }

        ///read the phone number
        if (argv[i+1] != NULL &&
                argv[i] != NULL &&
                strcmp(argv[i], "-phone") == 0
           )
        {
            phone.append(argv[i+1]);
            if(!validatePhone(phone))
            {
                cout << "Improperly formatted phone number, please use: xxx-xxx-xxxx" << endl;
            }
            else
            {
                cout << "phone number: " << phone << endl;
            }

            i += 2; /// move forward to the address
        }
        else
        {
            cout << "Error no or bad phone number specified" << endl;
        }
        ///read the address
        ///if error don't continue
        ///else continue
        if (argv[i+1] == NULL ||
                argv[i] == NULL ||
                strcmp(argv[i], "-addr") != 0)
        {
            cout << "Error no or bad address specified" << endl;
        }
        else
        {
            cout << "address: ";
            ///read the address
            while ( strcmp(argv[i],"-notes") != 0 && argv[i+1] != NULL)
            {
                ///we do not want to read the address as a name or notes
                if (strcmp(argv[i],"-notes") && strcmp(argv[i], "-addr"))
                {
                    address.append(argv[i]);
                    address += " ";    ///keep the spaces
                }
                i++;
            }
            cout << address << endl;

        }
//        cout << "index: " << argv[i] << endl;
        ///read the notes
        if (argv[i] == NULL ||
                argv[i+1] == NULL ||
                strcmp(argv[i], "-notes") != 0)
        {
            cout << "Error no or bad note entry specified" << endl;
        }
        else
        {
            cout << "notes: ";
            ///read til the -file flag to get all the notes
            while ( argv[i] != NULL && strcmp(argv[i],"-file") != 0)
            {
                ///we do not want to read the notes flag as an info-note
                if (strcmp(argv[i],"-notes") != 0)
                {
                    notes.append(argv[i]);
                    notes += " ";    ///keep the spaces
                }
                i++;
            }
            cout << notes << endl;
        }

        ///read the filename
        if (argv[i+1] != NULL &&
                argv[i] != NULL &&
                strcmp(argv[i], "-file") == 0
           )
        {
            FILE_NAME.append(argv[i+1]);
            cout << "file name: " << FILE_NAME << endl;
        }
        else
        {
            cout << "Error no or bad file name specified" << endl;
        }

        cout << "Appending new entry" << endl;

        ///write the new entry
        file.open(FILE_NAME.c_str(), ios::in | ios::out );
        if(file.fail())
        {
            file.open(FILE_NAME.c_str(), ios::out );
            file.close();
            file.open(FILE_NAME.c_str(), ios::in | ios::out );
        }
        file.clear();
        file.seekp(0, ios::end);
        file << name << endl;
        file << age << endl;
        file << personId<< endl;
        file << rating << endl;
        file << phone << endl;
        file << address << endl;
        file << notes << endl;
        file.close();
    }///finally we hit another flag, this one is to dump the whole database to stdout
    else if (modeFlag == "-d" || modeFlag == "-D")
    {
        if (argv[2] != NULL)
        {
            FILE_NAME.append(argv[2]);
            database = readDb(file,FILE_NAME);
            dumpEntries(database,database[0].db_size);
        }
        else
        {
            cout << "Error no file name specified" << endl;
        }
    }///print a single entry from the db
    else if (modeFlag == "-p" || modeFlag == "-P")
    {
        int index = -1;
        if (argv[2] != NULL && argv[3] != NULL && atoi(argv[3]) >= 0 )
        {
            index = atoi(argv[3]);
            FILE_NAME.append(argv[2]);
            database = readDb(file,FILE_NAME);
            printPerson(database,index);
        }
        else
        {
            cout << "Error no file name or no/invalid index specified" << endl;
        }
    }///sort the db
    else if (modeFlag == "-s" || modeFlag == "-S")
    {
        cout << "Sort mode" << endl;
        int sortMode = -1;
        int lastSort = -1;
        if (argv[2] != NULL && argv[3] != NULL && atoi(argv[3]) >= 0 )
        {
            sortMode = atoi(argv[3]);
            FILE_NAME.append(argv[2]);
            database = readDb(file,FILE_NAME);
            sortPerson(file, FILE_NAME, database,lastSort,database[0].db_size,sortMode);
        }
    }///search/find an entry
    else if (modeFlag == "-f" || modeFlag == "-F")
    {
        cout << "Find mode" << endl;
        int sortMode = -1;
        if (argv[2] != NULL && argv[3] != NULL && atoi(argv[3]) >= 0 )
        {
            string searchTerm;
            FILE_NAME.append(argv[2]);
            sortMode = atoi(argv[3]);

            ///gather up the search phrase
            for (int i = 4; argv[i] != NULL; i++)
            {
                searchTerm.append(argv[i]);
            }
            database = readDb(file,FILE_NAME);
            int index = cmdModeFindPerson(database,database[0].db_size,sortMode,searchTerm);
            printPerson(database,index);
        }
    }///backup a database
    else if (modeFlag == "-b" || modeFlag == "-B")
    {
        if (argv[2] != NULL)
        {
            FILE_NAME.append(argv[2]);
            database = readDb(file,FILE_NAME);
            dumpEntries(database,database[0].db_size);
            writeDatabase(file, (FILE_NAME+=".bak"), database, database[0].db_size);
        }
        else
        {
            cout << "Error no file name specified" << endl;
        }
    }///print a help/summary of options and flags
    else if (modeFlag == "-h" || modeFlag == "-H")
    {
        modeSummary();
    }
    else
    {
        cout << "Sorry I do not know that mode" << endl;
        modeSummary();
    }

    if(wasRead)
    {
        cout << "Writing to disk." << endl;
        writeDatabase(file,FILE_NAME,database,SIZE);
    }

    if (database != NULL)
    {
        delete [] database;
    }

    return 0;
}
void modeSummary()
{
    cout << endl << "APPEND AN ENTRY: (all on one line)" << endl;
    cout <<  "\tdatabasecmdlineintfc.exe -a" << endl;
    cout <<  "\t\t-name [name]" << endl;
    cout <<  "\t\t-age [age]" << endl;
    cout <<  "\t\t-pid [personid]" << endl;
    cout <<  "\t\t-rating [rating]" << endl;
    cout <<  "\t\t-phone [phone]" << endl;
    cout <<  "\t\t-addr [address]" << endl;
    cout <<  "\t\t-notes [notes]" << endl;
    cout <<  "\t\t-file [filename]" << endl << endl;

    cout <<  "DUMP A WHOLE DATABASE: " << endl;
    cout <<  "\tdatabasecmdlineintfc.exe -d [filename]" << endl << endl;

    cout << "SORT A DATABASE: " << endl;
    cout << "\tdatabasecmdlineintf.exe -s [filename] [sortmode]" << endl;
    cout << "\tchoose one of the following sort options:" << endl;
    cout << "\t==>name   (0)\n";
    cout << "\t==>age    (1)\n";
    cout << "\t==>ID     (2)\n";
    cout << "\t==>rating (3)\n";
    cout << "\t==>phone  (4)\n";
    cout << "\t==>address(5)\n";
    cout << "\t==>info   (6)\n\n";

    cout << "FIND AN ENTRY IN A DATABASE: " << endl;
    cout << "\tdatabasecmdlineintf.exe -f [filename] [find-mode] [search-term]" << endl;
    cout << "\t(requires a previous sort by the appropriate field)" << endl << endl;

    cout << "BACKUP A DATABASE: " << endl;
    cout << "\tdatabasecmdlineintf.exe -b [filename]" << endl << endl;

    cout << "INTERACTIVE MODE:" << endl;
    cout << "\tdatabasecmdlineintf.exe" << endl << endl;

    cout << "PRINT THIS HELP MENU:" << endl;
    cout << "\tdatabasecmdlineintf.exe -h" << endl;

}
