#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//print every permutation of 1's and 0's for vector<bool> myvec
int main()
{
	vector<bool> myvec{0,0};
	sort(myvec.begin(),myvec.end());
	
	for (auto i=0; i<=myvec.size(); i++)
	{
		cout << "i=" << i << endl;
		cout << "myvec.size()=" << myvec.size() << endl;
		
		for(auto k=0;k<myvec.size();k++)myvec[k]=0;
		for(auto k=0;k<i;k++)myvec[k]=1;
		
		sort(myvec.begin(),myvec.end());
		do
		{
			for(auto j=0; j<myvec.size(); j++)
			{
				cout<<myvec[j];
			}
			cout << endl;
		}
		while(next_permutation(myvec.begin(),myvec.end()));
	}
}
