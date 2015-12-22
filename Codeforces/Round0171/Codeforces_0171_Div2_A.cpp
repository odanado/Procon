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

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

typedef unsigned long long ull;
typedef long long ll;

const int INF=100000000;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

using namespace std;

typedef pair<int ,int > P;

int n,m;

int main()
{
	cin>>n>>m;
	int x=0;
	int y=0;
	int ans=0;

	if(n==0&&m==0)
	{
		cout<<"0"<<endl;
		return 0;
	}
	if(n==1&&m==0)
	{
		cout<<"0"<<endl;
		return 0;
	}

	rep(i,10000)
	{
		if(!i) continue;
		//cout<<x<<","<<y<<endl;
		if(i%2==1)
		{
			x+=i;
			ans++;
			if(x==n&&y==m)
			{
				cout<<ans-1<<endl;
				return 0;
			}
			//printf("[debug]:%d,%d,%d,%d,%d\n",x,y,n,m,i);
			if(y==m&&x-i<=n&&n<=x)
			{
				cout<<ans-1<<endl;
				return 0;
			}
			y+=i;
			ans++;
			if(x==n&&y==m)
			{
				cout<<ans-1<<endl;
				return 0;
			}
			if(x==n&&y-i<=m&&m<=y)
			{
				cout<<ans-1<<endl;
				return 0;
			}
		}
		else
		{
			x-=i;
			ans++;
			if(x==n&&y==m)
			{
				cout<<ans-1<<endl;
				return 0;
			}
			if(y==m&&x<=n&&n<=x+i)
			{
				cout<<ans-1<<endl;
				return 0;
			}

			y-=i;
			ans++;
			if(x==n&&y==m)
			{
				cout<<ans-1<<endl;
				return 0;
			}
			if(x==n&&y<=m&&m<=y+i)
			{
				cout<<ans-1<<endl;
				return 0;
			}

		}


	}
	


	return 0;
}

//http://www.codeforces.com/contest/279/problem/A
