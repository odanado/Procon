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
	int n,y;
	while(cin>>n)
	{
		if(!n) return 0;
		int b,r,t;
		cin>>y;
		double max=-1.0;
		int max_index;

		rep(i,n)
		{
			cin>>b>>r>>t;
			if(t==1)
			{
				if(max<(1.0+(double)y*(double)r/100.0))
				{
					max=(1.0+(double)y*(double)r/100.0);
					max_index=b;
				}
			}
			else
			{
				if(max<(pow(1.0+(double)r/100.0,y)))
				{
					max=((pow(1.0+(double)r/100.0,y)));
					max_index=b;
				}
			}
		}
		cout<<max_index<<endl;

	}
		return 0;
}


