#include <iostream>
#include <limits>

using namespace std;

int main()
{
    //the size of the twelve types
    cout << "Size of a bool: " << sizeof(bool) << endl;
    cout << "Size of a char: " << sizeof(char) << endl;
    cout << "Size of an unsigned char:" << sizeof(unsigned char) << endl;
    cout << "Size of a short:" << sizeof(short) << endl;
    cout << "Size of an unsigned short:" << sizeof(unsigned short) << endl;
    cout << "Size of an int:" << sizeof(int) << endl;
    cout << "Size of a long int:" << sizeof(long int) << endl;
    cout << "Size of a long long int:" << sizeof(long long int) << endl;
    cout << "Size of an unsigned int:" << sizeof(unsigned int) << endl;
    cout << "Size of a float:" << sizeof(float) << endl;
    cout << "Size of a double:" << sizeof(double) << endl;
    cout << "Size of a long double:" << sizeof(long double) << endl;

    //the numeric limits of the twelve types
    cout << "Minimum value for bool: " << numeric_limits<bool>::min() << endl;  //this one is not surprising 0 then 1
    cout << "Maximum value for bool: " << numeric_limits<bool>::max() << endl;
    cout << "Minimum value for char: " << numeric_limits<char>::min() << endl;  //this one prints characters that I assume
    cout << "Maximum value for char: " << numeric_limits<char>::max() << endl;  //are the highest and lowest in terms of numeric value
    cout << "Minimum value for unsigned char: " << numeric_limits<unsigned char>::min() << endl;    //these have no output on my machine which is kinda boring
    cout << "Maximum value for unsigned char: " << numeric_limits<unsigned char>::max() << endl;
    cout << "Minimum value for short: " << numeric_limits<short>::min() << endl;
    cout << "Maximum value for short: " << numeric_limits<short>::max() << endl;
    cout << "Minimum value for unsigned short: " << numeric_limits<unsigned short>::min() << endl;
    cout << "Maximum value for unsigned short: " << numeric_limits<unsigned short>::max() << endl;
    cout << "Minimum value for int: " << numeric_limits<int>::min() << endl;
    cout << "Maximum value for int: " << numeric_limits<int>::max() << endl;
    cout << "Minimum value for long int: " << numeric_limits<long int>::min() << endl;
    cout << "Maximum value for long int: " << numeric_limits<long int>::max() << endl;
    cout << "Minimum value for long long int: " << numeric_limits<long long int>::min() << endl;
    cout << "Maximum value for long long int: " << numeric_limits<long long int>::max() << endl;
    cout << "Minimum value for unsigned int: " << numeric_limits<unsigned int>::min() << endl;
    cout << "Maximum value for unsigned int: " << numeric_limits<unsigned int>::max() << endl;
    cout << "Minimum value for float: " << numeric_limits<float>::min() << endl;
    cout << "Maximum value for float: " << numeric_limits<float>::max() << endl;
    cout << "Minimum value for double: " << numeric_limits<double>::min() << endl;
    cout << "Maximum value for double: " << numeric_limits<double>::max() << endl;
    cout << "Minimum value for long double: " << numeric_limits<long double>::min() << endl;    //this is pretty weird too I get -0 for this
    cout << "Maximum value for long double: " << numeric_limits<long double>::max() << endl;    //on my machine I get #QNAN for this which is apparently a string constant

    cout << "*Press enter key to quit*" << endl;
    cin.get();
    return 0;
}
