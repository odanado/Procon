#include<algorithm>
#include<iostream>

using namespace std;

int t,n;
int s,f;

int main()
{
	while(cin>>t)
	{
		if(!t) return 0;

		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>s>>f;
			t-=(f-s);
		}

		if(t>0) cout<<t<<endl;
		else cout<<"OK"<<endl;

	}
	return 0;
}
