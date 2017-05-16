#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

//the function in the spec
double fallingDistance(double);

int main()
{
    //setup cout
    cout << fixed << setprecision(2);

    //setting some column headers for aesthetics
    //my field widths are 8 but I added two spaces between
    //each column because I like the way it looks..
    cout << "time      " << "distance"<< endl;
    cout << "########  " << "########" << endl;
    //loop over the times being asked for
    for (int i = 1; i <= 10; i++)
    {
        //generate output
        //casted to a double because the function accepts doubles..
        cout << setw(8) << i << "  ";
        cout << setw(8) << fallingDistance((double)i);
        cout << endl;
    }
    return 0;
}

//http://keisan.casio.com/exec/system/1224835316
//I found this calculator that I used to double check my output values with
double fallingDistance(double t)
{
    //setup the equation variables
    t = pow(t,2);
    double g = 9.8;
    //dummy output
    return ((t*g)/2);
}
