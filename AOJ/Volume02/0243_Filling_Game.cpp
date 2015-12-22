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

int ans=INF;
int x,y;

inline int change(string ss)
{
	if(ss=="R") return 0;
	if(ss=="G") return 1;
	if(ss=="B") return 2;
}

inline bool check(vector<vector<int> > tile)
{
	rep(i,tile.size())
	{
		rep(j,tile[i].size())
		{
			if(tile[0][0]!=tile[i][j])
				return false;
		}
	}

	return true;

}

inline void f(vector<vector<int> > &tile,int color)
{
	//x,y
	queue<P> que;
	int oldcolor=tile[0][0];
	tile[0][0]=color;

	que.push(P(0,0));

	while(que.size())
	{
		P p = que.front(); que.pop();

		rep(i,4)
		{
			int nx=p.fr+dx[i];
			int ny=p.sc+dy[i];

			if(0<=nx&&nx<x&&0<=ny&&ny<y&&tile[nx][ny]==oldcolor)
			{
				tile[nx][ny]=color;	
				que.push(P(nx,ny));
			}
		}
	}
}	

inline void dfs(vector<vector<int> > tile,int depth)
{
	if(check(tile))
	{
		ans=min(ans,depth);
		return;
	}
	//最大でも18手を越えないらしい
	if(depth==17) return;

	vector<vector<int> > tile1=tile;
	vector<vector<int> > tile2=tile;

	if(tile[0][0]==0)
	{
		f(tile1,1);
		f(tile2,2);
	}
	if(tile[0][0]==1)
	{
		f(tile1,0);
		f(tile2,2);
	}
	if(tile[0][0]==2)
	{
		f(tile1,1);
		f(tile2,0);
	}

	dfs(tile1,depth+1);
	dfs(tile2,depth+1);

}

inline void solve()
{
	vector<vector<int> > tile;

	tile.reserve(10);

	rep(i,x)
	{
		vector<int> vec;
		vec.reserve(10);
		rep(j,y)
		{
			string c;
			cin>>c;
			vec.pb(change(c));
		}
		tile.pb(vec);
	}

	dfs(tile,0);

}

int main()
{
	while(cin>>x>>y)
	{
		swap(x,y);
		if(x==0&&y==0)
			return 0;

		solve();
		cout<<ans<<endl;
		ans=INF;

	}
	return 0;
}
