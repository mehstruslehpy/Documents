#include <iostream>
#include <iomanip>
using namespace std;
//Use a nested to print out times table from 1 to 10
int main()
{
    for(int i = 1; i <= 100; i++) //rows
    {
        for(int j = 1; j <= 100; j++) //columns
        {
            cout << setw(4) << i*j;
        }
        cout << endl;
    }

    return 0;
}
