#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    string name;
    string favCity;
    string college;
    string profession;
    string favAnimal;
    string petName;
    string fullText;

    //I avoided the plain "cin << variable" style input because this way allows
    //every input to be multiple words
    cout << "Enter your name: \n";
    getline(cin, name);
    cout << "Enter your favorite city: \n";
    getline(cin, favCity);
    cout << "Enter the name of your college \n";
    getline(cin, college);
    cout << "Enter your current profession: \n";
    getline(cin, profession);
    cout << "Enter your favorite animal: \n";
    getline(cin, favAnimal);
    cout << "Enter the name of your pet: \n";
    getline(cin, petName);

    //concatenate all the input text together in a couple steps
    fullText = "Your name is " + name + " your favorite city is ";
    fullText = fullText + favCity + " you go to " + college;
    fullText = fullText + " you work as a " + profession;
    fullText = fullText + " your favorite animal is " + favAnimal;
    fullText = fullText + " your pets name is " + petName;
    cout << fullText;

    return 0;
}
