#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
    ///the output string
    int numRows = 0;
    int numCols = 0;
    string outMap = "{\t\n\t";
    ifstream inputFile;
    string inputString;
    string tempName;
    if ( argc == 2)
    {
        inputFile.open(argv[1]);
    }
    else
    {
        cout << "Please enter a map file: " << endl;
        getline(cin, tempName);
        inputFile.open(tempName.c_str());

    }
    while(getline(inputFile, inputString))
    {
        numRows++;
        if (numCols < inputString.length())
        {
            numCols = inputString.length() - 1; ///minus one begins the l end of line character
        }
        ///concatenate the quotes and braces
        if (inputString.find_first_not_of("e") != string::npos)
        {
            outMap += '{';
        }

        for (int i = 0; i < inputString.length(); i++)
        {
            if(inputString.at(i) == 'l')
            {
                outMap = outMap + '}' + ',' + '\n' + '\t';
            }
            else if (inputString.at(i) == 'e')
            {
                break;
            }
            else
            {
                outMap = outMap + '\'' + inputString.at(i) + '\''+',';
            }
        }

    }
    ///pop the last tab off to make the last brace fit nicely
    outMap.pop_back();
    outMap = outMap + "};";
    cout << outMap << endl;
    cout << "Rows: " << numRows - 1 << endl; ///minus two because the single e
    cout << "Cols: " << numCols - 1 << endl;
    inputFile.close();
}
