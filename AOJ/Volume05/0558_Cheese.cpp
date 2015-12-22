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

typedef pair<int,int> P;

int h,w,n;
string maze[1000];

	int dist[1000][1000];
int bfs(char s,char t)
{
	int sx,sy,tx,ty;
	rep(i,1000) rep(j,1000) dist[i][j]=INF;

	rep(i,h) rep(j,w) 
	{
		if(maze[i][j]==s)
		{
			sx=i;
			sy=j;
		}
		if(maze[i][j]==t)
		{
			tx=i;
			ty=j;
		}

	}

	dist[sx][sy]=0;
	queue<P> que;
	que.push(P(sx,sy));

	while(que.size())
	{
		P p = que.front();
		que.pop();
		if(p.fr==tx&&p.sc==ty)
			return dist[tx][ty];

		rep(i,4)
		{
			int nx=p.fr+dx[i];
			int ny=p.sc+dy[i];
			if(0<=nx&&nx<h&&0<=ny&&ny<w&&maze[nx][ny]!='X'&&dist[nx][ny]==INF)
			{
				que.push(P(nx,ny));
				dist[nx][ny] = dist[p.fr][p.sc]+1;
			}
		}
	}

	return -INF;
}

int main()
{
	cin>>h>>w>>n;

	rep(i,h) cin>>maze[i];

	rep(i,h) rep(j,w) if(maze[i][j]=='S') maze[i][j]='0';
	int ans=0;
	rep(i,n)
		ans+=bfs(i+'0',i+1+'0');

	cout<<ans<<endl;



		return 0;
}

