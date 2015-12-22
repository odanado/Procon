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

int V,k;

class edge
{
	public:

	int to;
	int cost;
	edge(int _to,int _cost)
	{
		this->to=_to;
		this->cost=_cost;
	}

};

vector<edge> G[107];
int d[107];

//s->tの最短距離
int dijkstra(int s,int t)
{
	priority_queue<P,vector<P>,greater<P> > que;
	fill(d,d+107,INF);
	d[s]=0;
	que.push(P(0,s));

	while(que.size())
	{
		P p=que.top();
		que.pop();

		if(p.sc==t) return d[t];

		rep(i,G[p.sc].size())
		{
			edge e = G[p.sc][i];
			if(d[e.to] > d[p.sc] + e.cost)
			{
				d[e.to] = d[p.sc] + e.cost;
				que.push(P(d[e.to],e.to));
			}
		}
	}
	return INF;
}

void solve()
{
	rep(i,107) G[i].clear();

	rep(i,k)
	{
		int a,b,c,e;
		cin>>a;
		if(a==0)
		{
			cin>>b>>c;
			int ans=dijkstra(b,c);
			if(ans==INF) cout<<"-1"<<endl;
			else cout<<ans<<endl;
		}
		else
		{
			cin>>b>>c>>e;
			G[b].pb(edge(c,e));
			G[c].pb(edge(b,e));
		}

	}


}

int main()
{
	while(cin>>V>>k)
	{
		if(V==0&&k==0) return 0;
		solve();
	}
		return 0;
}


