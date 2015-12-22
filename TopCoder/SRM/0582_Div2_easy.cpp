#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>


using namespace std;

class SemiPerfectSquare
{
public: string check(int N)
	{
		vector<int> squ;

		for(int i=2;i<=32;i++)
			squ.push_back(i*i);

		for(int i=0;i<squ.size();i++)
		{
			if(N==squ[i])
				return "Yes";

			if((double)N/(double)squ[i] == N/squ[i])
			{
				if((int)sqrt((double)squ[i])>N/squ[i])
				{
				cout<<squ[i]<<","<<N/squ[i]<<endl;
					return "Yes";
				}
			}
		}
		return "No";

	}

};

int main()
{
	int n;
	cin>>n;

	SemiPerfectSquare obj;

	cout<<obj.check(n);

	return 0;
}
