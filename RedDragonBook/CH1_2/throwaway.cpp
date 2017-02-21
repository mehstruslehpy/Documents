#include <iostream>

using namespace std;

int main()
{
int i = 0;
int j = 0;
int n;
cin >> n;

for (j = 1; j <= n; j++)
{
	for (i = 1; i <= j; i++)
	{
		cout << "*";
	}
	cout << endl;
}
}
