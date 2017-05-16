#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;
const int PPL = 7;
const int FEAT = 10;
struct Person
{
    string name;
    int age;
    int* features;
    int numFeatures;
};

void getPerson(Person *, int);
void showPerson(Person *, int);
int main()
{
    srand(time(0));

    string stringFeatures[FEAT] = {"BIG FEET","UGLY","BALD","NICE MUSTACHE","FULL OF CALCIUM","SUNNY DISPOSITION","NOT TOO ANNOYING","OKAY ATTITUDE","DECENT SUNGLASSES","+2 SHOES OF AGILITY"};
    Person people[PPL];
    cout << "####INPUT####" << endl;
    getPerson(people, PPL);
    cout << "####OUTPUT####" << endl;
    showPerson(people, PPL);

    return 0;
}

void getPerson(Person *input, int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << "Person number " << i << ": " << endl;
        cout << "name: ";
        cin >> input[i].name;
        input[i].age = rand() % 110 + 1;
        cout << "age: " << input[i].age << endl;
        input[i].numFeatures = rand() % 5 + 1;
        cout << "Number of features: " << input[i].numFeatures << endl;
        input[i].features = new int[input[i].numFeatures];

        for (int n = 0; n < input[i].numFeatures - 1; n++)
        {
            input[i].features[n] = rand() % (FEAT - 1);
        }
    }
}

void showPerson(Person *input, int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << "Person number " << i << ": " << endl;
        cout << "name: ";
        cout << input[i].name;
        cout << "age: " << input[i].age << endl;
        cout << "Number of features: " << input[i].numFeatures << endl;
        cout << "Feature " << endl;
        for (int n = 0; n < input[i].numFeatures - 1; n++)
        {
            cout << "Feature " << n << ": " << endl;
            input[i].features[n];
        }
    }
}
