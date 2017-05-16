#include <iostream>
#include <time.h>
#include "fish.h"
#include "player.h"

using namespace std;

int main()
{
    Player p;
    string choice = "";
    srand(time(NULL));

    ///priming read
    cout << "Go fish? [y/n]" << endl;
    getline(cin,choice);
    while (choice != "n" && choice != "N")
    {
        p.goFish();
        p.sortInventory();
        p.printInventory();
        p.getTotalScore();
        cout << "Go fish?" << endl;
        getline(cin,choice);

    }

}
