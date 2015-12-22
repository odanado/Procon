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

int maze[12][12];

void show()
{
	rep(i,12)
	{
		rep(j,12)
		{
			cout<<maze[i][j];
		}
		cout<<endl;
	}

}

void dfs(int x,int y)
{
	maze[x][y]=0;
	rep(i,4)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];

		if(0<=nx&&nx<12&&0<=ny&&ny<12&&maze[nx][ny]==1)
			dfs(nx,ny);
	}

}
int main()
{
	string str;
	while(cin>>str)
	{
		int ans=0;
		rep(i,12) maze[0][i]=str[i]-'0';
		rep(i,11)
		{
			cin>>str;
			rep(j,12)
			{
				maze[i+1][j]=str[j]-'0';
			}
		}

		rep(i,12) rep(j,12)
		{
			if(maze[i][j]==1)
			{
				ans++;
				dfs(i,j);
			}
		}

		cout<<ans<<endl;

	}
	return 0;
}
