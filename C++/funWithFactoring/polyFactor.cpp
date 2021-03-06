#include <iostream>
#include <vector>
#include <string>

using namespace std;

int findZeros(vector<int> coeff);

int main()
{
    string input;
    vector<int> coeff;
    int inter;

    cout << "Input leading integral coefficients a_n*x^n, (a_n-1)(x^(n-1)), ... , a_0 press enter between each one " << endl;
    cout << "enter zero for missing terms like 0x^2" << endl;
    cout << "enter STOP to end your input." << endl;

//	getline(cin,input);

    while (input != "STOP")
    {
        getline(cin,input);
        inter = atol(input.c_str());
        coeff.push_back(inter);
    }
    /*
    	for(int i = 0; i < coeff.size() - 1; i++)
    	{
    		cout << coeff[i] << " ";
    	}
    	cout << endl;
    */
    coeff.pop_back();
    //find zeros from here using the division algorithm

    //while (findZeros(coeff) != -1);
    cout << "FINDING ZEROS" << endl;
    findZeros(coeff);
}

int findZeros(vector<int> coeff)
{
    int lead = coeff[0];
    int trail = coeff[coeff.size() - 1];
    vector<int> zeros;
    int result = 1;
    int row1 = 0;
    int row2 = 0;
    int row3 = 0;
    /*
    	_-2|  1  2  4  8
    	      | -2  0 -8
    	   -------------
    	      1  0  4  0
    */
    if ( trail > 0)
    {
        for (int i = 1; i <= trail; i++)
        {
            if ( trail % i == 0 )
            {
                for (int j = 0; j < coeff.size(); j++)
                {
                    result = row3;
                    row1 = coeff[j];
                    row3 = row1 + row2;
                    row2 = i * row3;
                    cout << "i:" << i;
                    cout << "|" <<result << "| ";
                    cout << row1 << " ";
                    cout << row2 << " ";
                    cout << row3 << " " << endl;
                }

                if (row3 == 0)
                {
                    cout << i << " is a zero" << endl;
                }
            }
        }
    }
	else if (trail < 0)
	{
	    for (int i = -1; i >= trail; i--)
        {
            if ( trail % i == 0 )
            {
                for (int j = 0; j < coeff.size(); j++)
                {
                    result = row3;
                    row1 = coeff[j];
                    row3 = row1 + row2;
                    row2 = i * row3;
                    cout << "i:" << i;
                    cout << "|" <<result << "| ";
                    cout << row1 << " ";
                    cout << row2 << " ";
                    cout << row3 << " " << endl;
                }

                if (row3 == 0)
                {
                    cout << i << " is a zero" << endl;
                }
            }
        }
 
	}
	else
	{
		cout << "ERROR" << endl; 
	}
	return -1;
}
