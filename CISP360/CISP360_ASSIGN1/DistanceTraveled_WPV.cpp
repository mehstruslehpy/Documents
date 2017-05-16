#include <iostream>
#define SPEED_OF_SOUND 4.689    //I don't know if this can be done with more accuracy but if we do a define in this
                                //manner it is easier to update later and the code looks nice at line 17
                                //const double = someNumber; would also probably work
using namespace std;

int main()
{


    float userTime;
    float outputDist;

    //ask for input
    cout << "Input the seconds you counted between the lightning and thunder: " << endl;
    cin >> userTime;
    //calculate the output
    outputDist = userTime / SPEED_OF_SOUND;
    //actually output now
    //this could be done with userTime / SPEED_OF_SOUND too if you want to get rid of outputDist and line 18
    cout << "The lightning was " << outputDist << " miles away" << endl;

    return 0;
}
