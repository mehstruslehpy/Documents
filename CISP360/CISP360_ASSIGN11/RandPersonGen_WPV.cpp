#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;
///data
const int PPL = 7;
const int FEAT = 10;

struct Person
{
    string name;
    int age;
    int* features;
    int numFeatures;
};

///functions
void sort(Person *, int);
void showNames(Person*, int);
void getPerson(Person *, int);
void freePerson(Person*, int);
void showPerson(Person *, int, string *);
int binSearch(Person*, string, int);
void printMenu();

int main()
{


    srand(time(0));

    ///basic stuff
    string stringFeatures[FEAT] = {"SUSPICIOUSLY LARGE THUMBS","UGLY","BALD",
                                   "NICE MUSTACHE","FULL OF CALCIUM",
                                   "WEIRD EYE TWITCH","NOT TOO ANNOYING",
                                   "LAZY EYE","SMELLS LIKE HAM",
                                   "+2 SHOES OF AGILITY"};
    Person people[PPL];
    ///repl stuff
    char choice;
    string srchName;
    int foundIndex = -1;

    cout << "PLEASE INPUT STARTING VALUES..." << endl;
    getPerson(people, PPL);
    cout << "SORTING THE LIST..." << endl;
    showNames(people, PPL);
    sort(people, PPL);
    cout << "THE LIST IS SORTED..." << endl;
    showNames(people, PPL);
    ///showPerson(people, PPL, stringFeatures);
    do
    {
        printMenu();
        cin >> choice;

        switch (choice)
        {
        case 's':
        case 'S':
            cout << "Choose a name to search: ";
            cin >> srchName;
            foundIndex = binSearch(people,srchName,PPL);
            if (foundIndex != -1)
            {
                cout << "Match at index " << foundIndex << endl << endl;
                showPerson(people+foundIndex, 1, stringFeatures);

            }
            else
            {
                cout << srchName<< " not found." << endl;
            }
            break;
        case 'n':
        case 'N':
            showNames(people,PPL);
            break;
        case 'd':
        case 'D':
            showPerson(people, PPL, stringFeatures);
            break;
        case 'R':
        case 'r':
            freePerson(people, PPL);
            getPerson(people, PPL);
            sort(people, PPL);
            break;
        default:
            cout << "Sorry I did not understand your input" << endl;
        case 'Q':
        case 'q':
            break;


        }
    }while ( choice != 'q' && choice != 'Q');

    ///clean up and leave
    freePerson(people, PPL);
    cout << "See ya later!" << endl;
    return 0;
}

void getPerson(Person *input, int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
        cout << "Person number " << i << ": " << endl;
        cout << "name: ";
        ///cin >> input[i].name;
        getline(cin,input[i].name);
        input[i].age = rand() % 110 + 1;
        cout << "age: " << input[i].age << endl;
        input[i].numFeatures = rand() % 5 + 1;
        cout << "Number of features: " << input[i].numFeatures << endl;
        input[i].features = new int[input[i].numFeatures];

        for (int n = 0; n < input[i].numFeatures; n++)
        {
            input[i].features[n] = rand() % (FEAT - 1);
            ///cout << "DEBUG FEAT:" << input[i].features[n] << endl;
        }
        cout << endl; ///looks good
    }
}

void showPerson(Person *input, int ilength, string *features)
{
    for (int i = 0; i < ilength; i++)
    {
        cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
        cout << "Person number " << i << ": " << endl;
        cout << "name: " << input[i].name << endl;
        cout << "age: " << input[i].age << endl;
        cout << "Number of features: " << input[i].numFeatures << endl;
        cout << "Features: " << endl;
        for (int n = 0; n < input[i].numFeatures; n++)
        {
            cout << "\tFeature " << n << ": " << endl;
            cout << "\t\t" << input[i].features[n] << ": " << features[input[i].features[n]] << endl;
        }
        cout << endl; ///looks good
    }
}

void showNames(Person* input, int length)
{
    cout << endl;
    for (int i = 0; i < length; i++)
    {
        cout << "Name " << i << ": " << input[i].name << endl;
    }
    cout << endl;
}

void freePerson(Person* input, int length)
{
    for (int i = 0; i < length; i++)
    {
        delete(input[i].features);
    }
    cout << endl << "Freeing memory" << endl;
}

void sort(Person *input, int size)
{
    ///startScan, minIndex, minValue
    Person minV;    ///we could probably do this with only one string but a single Person is not too huge
    int sScan, minI;
    for (int sScan = 0; sScan < (size - 1); sScan++)
    {
        minI = sScan;
        minV = input[sScan]; ///p[sScan]
        for (int i = sScan + 1; i < size; i++)
        {
            if (input[i].name < minV.name)  ///the value to sort by is the name
            {
                minV = input[i];
                minI = i;
            }
        }
        input[minI] = input[sScan];
        input[sScan] = minV;
    }
}

int binSearch(Person *input, string name, int size)
{
    int first = 0;
    int last = size;
    bool found = false;
    int position = -1;
    while (!found && first <= last)
    {
        int middle = (first + last) / 2;
        //if (arr[middle] == name || arr[middle].find(name) != string::npos)
        if (input[middle].name == name)
        {
            found = true;
            position = middle;
        }
        else if (input[middle].name > name)
        {
            last = middle - 1;
        }
        else
        {
            first = middle + 1;
        }
    }
    return position;
}
void printMenu()
{
    cout << "Press S/s to search the list" << endl;
    cout << "Press N/n to display all the names" << endl;
    cout << "Press D/d to dump the full list" << endl;
    cout << "Press R/r to reinitialize the list" << endl;
    cout << "Press Q/q to quit" << endl;
}
