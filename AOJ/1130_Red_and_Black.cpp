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

int ans;
int w,h;
char maze[27][27];

void dfs(int x,int y)
{
	//printf("[debug]:%d,%d\n",x,y);
	maze[x][y]='#';
	rep(i,4)
	{
		int nx=dx[i]+x;
		int ny=dy[i]+y;
		if(maze[nx][ny]=='.')
		{
			ans++;
			dfs(nx,ny);
		}
	}

}

void solve()
{
	/*
	rep(i,25)
	{
		rep(j,25)
		{
			cout<<maze[i][j];
		}
		cout<<endl;
	}
	*/
	rep(i,h) rep(j,w)
	{
		if(maze[i][j]=='@')
		{
			dfs(i,j);
			cout<<ans+1<<endl;
			return;
		}
	}


}

int main()
{
	rep(i,25) rep(j,25) maze[i][j]='#';
	
	while(cin>>w>>h)
	{
		if(w==0&&h==0) return 0;
		rep(i,h) rep(j,w) 
		{
			cin>>maze[i][j];
		}
		solve();
		ans=0;
		rep(i,25) rep(j,25) maze[i][j]='#';
	}


	return 0;
}


