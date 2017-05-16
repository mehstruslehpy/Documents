#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>

using namespace std;
///data
struct Person
{
    string name;
    int age;
    int* features;
    int numFeatures;
};

///functions
void sort(vector<Person>&, int);
void showNames(vector<Person>&, int);
void getPerson(vector<Person>&, int, int);
void freePerson(vector<Person>&, int);
void clearPerson(vector<Person>&, int);
void showPerson(vector<Person>&, int, vector <string> &);
int binSearch(vector<Person>&, string, int);
void printMenu();
void initFeat(vector <string> &,int);

int main()
{
    int PPL = 7;
    int FEAT = 10;

    srand(time(0));

    ///basic stuff
    vector<string>  stringFeatures = {"SUSPICIOUSLY LARGE THUMBS","UGLY","BALD","NICE MUSTACHE","FULL OF CALCIUM","WEIRD EYE TWITCH","NOT TOO ANNOYING","LAZY EYE","SMELLS LIKE HAM","+2 SHOES OF AGILITY"};
    vector<Person> people;
    ///repl stuff
    char choice;
    string srchName;
    int foundIndex = -1;

    ///extended mode options
    cout << "Would you like to use the default features? [y/n]" << endl;
    cin >> choice;

    if (choice == 'n' || choice == 'N')
    {
        cout << "How many features?" << endl;
        cin >> FEAT;
        cout << "How many people?" << endl;
        cin >> PPL;

        initFeat(stringFeatures, FEAT);
    }
    else
    {
        ///not sure exactly why I need this...
        cin.ignore(256,'\n');
    }



    cout << "PLEASE INPUT STARTING VALUES..." << endl;
    getPerson(people, PPL, FEAT);
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
                ///showPerson(people+foundIndex, 1, stringFeatures);
                cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
                cout << "Person number " << foundIndex << ": " << endl;
                cout << "name: " << people[foundIndex].name << endl;
                cout << "age: " << people[foundIndex].age << endl;
                cout << "Number of features: " << people[foundIndex].numFeatures << endl;
                cout << "Features: " << endl;
                for (int n = 0; n < people[foundIndex].numFeatures; n++)
                {
                    cout << "\tFeature " << n << ": " << endl;
                    cout << "\t\t" << people[foundIndex].features[n] << ": " << stringFeatures[people[foundIndex].features[n]] << endl;
                }
                cout << endl; ///looks good
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
            cin.ignore(256,'\n');
            getPerson(people, PPL, FEAT);
            sort(people, PPL);
            break;
        case 'f':
        case 'F':
            initFeat(stringFeatures, FEAT);
            break;
        case 'c':
        case 'C':
            clearPerson(people, PPL);

            cout << "How many features?" << endl;
            cin >> FEAT;
            cout << "How many people?" << endl;
            cin >> PPL;

            initFeat(stringFeatures, FEAT);
            getPerson(people, PPL, FEAT);
            sort(people, PPL);
            break;
        default:
            cout << "Sorry I did not understand your input" << endl;
        case 'Q':
        case 'q':
            break;


        }
    }
    while ( choice != 'q' && choice != 'Q');

    ///clean up and leave
    freePerson(people, PPL);
    cout << "See ya later!" << endl;
    return 0;
}

void getPerson(vector<Person>&output, int length, int featCount)
{
    output.clear();
    Person input;
    for (int i = 0; i < length; i++)
    {
        cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
        cout << "Person number " << i << ": " << endl;
        cout << "name: ";
        ///cin >> input[i].name;
        getline(cin,input.name);
        input.age = rand() % 110 + 1;
        cout << "age: " << input.age << endl;
        input.numFeatures = rand() % 5 + 1;
        cout << "Number of features: " << input.numFeatures << endl;
        input.features = new int[input.numFeatures];

        for (int n = 0; n < input.numFeatures; n++)
        {
            input.features[n] = rand() % (featCount - 1);
            ///cout << "DEBUG FEAT:" << input[i].features[n] << endl;
        }
        cout << endl; ///looks good
        output.push_back(input);
    }
}

void showPerson(vector<Person>&input, int ilength, vector <string> &features)
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

void showNames(vector<Person>& input, int length)
{
    cout << endl;
    for (int i = 0; i < length; i++)
    {
        cout << "Name " << i << ": " << input[i].name << endl;
    }
    cout << endl;
}

void freePerson(vector<Person>& input, int length)
{
    for (int i = 0; i < length; i++)
    {
        delete(input[i].features);
    }
    cout << endl << "Freeing memory" << endl;
}

void clearPerson(vector<Person>& input, int length)
{
    for (int i = 0; i < length; i++)
    {
        input[i].name = "";
        input[i].age = 0;
        input[i].numFeatures = 0;
        delete(input[i].features);
    }
    cout << endl << "Clearing memory" << endl;
}

void sort(vector<Person>&input, int size)
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

int binSearch(vector<Person>&input, string name, int size)
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
    cout << "Press F/f to reinitialize the feature list" << endl;
    cout << "Press C/c to clear and reset everything" << endl;
    cout << "Press Q/q to quit" << endl;
}
void initFeat(vector <string> &feat, int length)
{

    feat.clear();
    string temp;
    cin.ignore(256,'\n');
    for (int i = 0; i < length; i++)
    {
        cout << "Input feature " << i << ": " << endl;
        getline(cin, temp);
        feat.push_back(temp);
    }
}
