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
int m;

int ary[100007];

void f(int a,int b,int c)
{
	if(ary[a]==0&&ary[b]==0)
	{
		if(ary[c]==1)
		{
			ary[a]=2;
			ary[b]=3;
		}
		else if(ary[c]==2)
		{
			ary[a]=1;
			ary[b]=3;
		}
		else
		{
			ary[a]=1;
			ary[b]=2;
		}
	}
}

void f2(int a,int b,int c)
{
	if(ary[a]==0&&ary[b]!=0&&ary[c]!=0)
	{
		if(ary[b]==1)
		{
			if(ary[c]==2)
				ary[a]=3;
			if(ary[c]==3)
				ary[a]=2;
		}
		if(ary[b]==2)
		{
			if(ary[c]==1)
				ary[a]=3;
			if(ary[c]==3)
				ary[a]=1;
		}
		if(ary[b]==3)
		{
			if(ary[c]==1)
				ary[a]=2;
			if(ary[c]==2)
				ary[a]=1;
		}
	}
}

int main()
{
	cin>>n>>m;

	rep(i,m)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(ary[a]==0&&ary[b]==0&&ary[c]==0)
		{
			ary[a]=1;
			ary[b]=2;
			ary[c]=3;
		}
		f(a,b,c);
		f(b,c,a);
		f(c,a,b);
		f2(a,b,c);
		f2(b,c,a);
		f2(c,b,a);

	}
	rep(i,n)
	{
		if(i) cout<<" "<<ary[i+1];
		else cout<<ary[i+1];

	}
	cout<<endl;

		return 0;
}


