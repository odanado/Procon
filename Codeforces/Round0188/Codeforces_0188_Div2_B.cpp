#include<algorithm>
#include<functional>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<climits>

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

typedef unsigned long long UInt64;
typedef long long Int64;

const int INF=100000000;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

using namespace std;

typedef pair<int ,int > P;


int main()
{
	string str;
	cin>>str;

	Int64 a=0,b=0;

	if(str.size()<5)
	{
		cout<<"0"<<endl;
		return 0;
	}

	rep(i,str.size()-4)
	{
		if(str[i]=='h' && str[i+1]=='e' && str[i+2]=='a' && str[i+3]=='v' && str[i+4]=='y')
		{
			a++;
		}
		if(str[i]=='m' && str[i+1]=='e' && str[i+2]=='t' && str[i+3]=='a' && str[i+4]=='l')
		{
			b+=a;
		}

	}

	cout<<b<<endl;

		


		return 0;
}

