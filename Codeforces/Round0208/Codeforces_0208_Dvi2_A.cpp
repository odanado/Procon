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
#define FOR(itr,data) for(__typeof((data).begin()) itr=(data).begin();itr!=(data).end();++itr)
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

int n;
int x[1007];
int ma=-INF;
int mi=INF;

int main()
{
	cin>>n;
	rep(i,n) cin>>x[i];

	rep(i,n) x[i]+=1000007;
		if(n==1)
				{
							puts("no");
									return 0;
										}
			else if(n==2)
					{
								puts("no");
										return 0;
											}


	rep(i,n-2)
	{
		if(i%2==0)
		{
			if(x[i] > x[i+2])
			{
				if(x[i-1]<x[i]&&x[i-1]<ma&&ma<x[i])
				{
					puts("yes");
					return 0;
				}
			}
		}
		else
		{
			if(x[i] < x[i+2])
			{
				if(x[i-1]>x[i]&&x[i]<mi&&mi<x[i-1])
				{
					puts("yes");
					return 0;
				}
			}
		}
		ma=max(ma,x[i]);
		mi=min(mi,x[i]);
	}
		puts("no");
		return 0;
}
