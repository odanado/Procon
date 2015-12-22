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

struct edge
{
	public:
	int to;
	int cost;
	//0:未使用 1:使用中 2:使用済み
	int ticket;
	edge(int _to,int _cost,int _ticket)
	{
		this->to=_to;
		this->cost=_cost;
		this->ticket=_ticket;
	}
	
	bool operator < (const edge &a,const edge &b)
	{
		return a.cost > b.cost;
	}
};

int n,m;
vector<edge> G[107];

void solve()
{
	int d[107][3];
	rep(i,107) d[i][0]=d[i][1]=d[i][2]=INF;

	priority_queue<edge> que;
	que.push(edge(0,0,0));


	while(que.size())
	{
		edge e1=que.top(); que.pop();
		int cost=e1.cost;
		int v=e1.to;
		int ticket=e1.ticket;

		rep(i,G[v].size())
		{
			edge e2=G[v][i];
			if(ticket==0)
			{
				if(d[e2.to][0] > d[v][0] + e2.cost)
				{
					d[e2.to][0]=d[v][0]+e2.cost;
					que.push(edge(e2.to,d[e2.to][0],0));
				}
				if(d[e2.to][1]>d[v][0])
				{
					d[e2.to][1]=d[v][0];
					que.push(edge(e2.to,d[e2.to][1],1));
				}
			}
			if(ticket==1)
			{
				if(d[e2.to][2]>d[v][1])
				{
					d[e2.to][2]=d[v][1];
					que.push(edge(e2.to,d[e2.to][2],2));
				}
			}
			else
			{
				if(d[e2.to][2] > d[v][2] + e2.cost)
				{
					d[e2.to][2]=d[v][2]+e2.cost;
					que.push(edge(e2.to,d[e2.to][2],2));
				}
			}
		}
	}

	int res=INF;
	rep(i,3) res=min(res,d[n-1][i]);
	cout<<res<<endl;
		

}

int main()
{
	while(cin>>n>>m)
	{
		if(n==0&&m==0) return 0;
		rep(i,m)
		{
			int a,b,c;
			cin>>a>>b>>c;
			G[a].pb(edge(b,c,0));
			G[b].pb(edge(a,c,0));
		}
		solve();
		rep(i,107) G[i].clear();

	}
		return 0;
}


