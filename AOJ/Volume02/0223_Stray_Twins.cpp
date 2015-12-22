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

//二人の位置といま何手目か

char maze[57][57];

class status
{
	int tx,ty;
	int kx,ky;
	int dist;

	status(int _tx,int _ty,int _kx,int _ky,int _dist)
	{
		this->tx=_tx;
		this->ty=_ty;
		this->kx=_kx;
		this->ky=_ky;
		this->dist=_dist;
	}
};

int dist[57][57][57][57];

int bfs(status _status)
{
	queue<status> que;
	que.push(_status);
	rep(i,57) rep(j,57) rep(k,57) fill(dist[i][j][k],dist[i][j][k]+57,INF);

	dist[sta.tx][sta.ty][sta.kx][sta.ky]=0;

	while(que.size())
	{
		status sta = que.front();
		que.pop();

		if(sta.tx==sta.kx&&sta.xy==sta.ky)
			return sta.dist;
		if(sta.dist==100)
			return -1;

		rep(i,4)
		{
			int ntx=sta.tx+dx[i];
			int nty=sta.ty+dy[i];
			int nkx=sta.kx+dx[i]*(-1);
			int nky=sta.ky+dy[i]*(-1);
			//両方が移動範囲外、片方が移動範囲外

			//たかゆき君は少なくとも移動できる
			if(0<=ntx&&ntx<x && 0<=nty&&nty<y&&maze[ntx][nty]==0)
			{
				//かずゆき君も移動できる
				if(0<=nkx&&nkx<x && 0<=nky&&nky<y &&maze[nkx][nky]==0  )
				{
					que.push(status(ntx,nty,nkx,nky,sta.dist+1));
					dist[ntx][nty][nkx][nky]=dist[sta.tx][sta.ty][sta.kx][sta.ky]+1;
				}
				else
				{
					que.push(status(ntx,nty,sta.kx,sta.ky,sta.dist+1));
				}
			}
			else
			{
				if(0<=nkx&&nkx<x && 0<=nky&&nky<y &&maze[nkx][nky]==0)
				{
					que.push(status(sta.tx,sta.ty,nkx,nky,sta.dist+1));
				}
			}
		}

	}

}

int main()
{
	int x,y;
	while(cin>>y>>x)
	{
		if(x==0&&y==0)
			return 0;
		rep(i,57) rep(j,57) maze[i][j]=1;
		int tx,ty;
		int kx,ky;
		cin>>tx>>ty;
		cin>>kx>>ky;

		rep(i,x) rep(j,y)
		{
			cin>>maze[i][j];
		}

		int ans=bfs(status(tx,ty,kx,ky,0));

		cout<<ans<<endl;
	}
	return 0;
}

