#include <iostream>
#include <iomanip>
using namespace std;

bool primeChecker(int);

int main()
{
    ///loop over the range we want to check
    for (int i = 1; i <= 100; i++)
    {
        cout << "Number:" << setw(3) << i;
        if ( primeChecker(i))
            cout << " is prime";
        else
            cout << " is not prime";
        cout << endl;
    }
    return 0;
}

///I already knew the test to do this I can't recall if you mentioned it in 300 or if I
///read it in a book but the way you do this is
///you check for divisibility backwards via modulo
///from the number - 1 (because a number is always divisible by itself)
///down to the number 2 (all numbers are divisible by one so going that low wont work)
///if the modulo returns 0 ever over this range
///then you know the input is not a prime number
bool primeChecker(int input)
{
    ///here's the loop explained above
    for (int i = input - 1; i > 1; i--)
    {
        if (input % i == 0)
        {
            return false;
        }
    }
    return true;
}
