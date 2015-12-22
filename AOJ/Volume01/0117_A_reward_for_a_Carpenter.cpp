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

int d[30];
vector<edge> G[30];

int n,m;

int dijkstra(int s,int t)
{
	priority_queue<P,vector<P> , greater<P> > que;
	fill(d,d+30,INF);
	d[s]=0;
	que.push(P(0,s));

	while(que.size())
	{
		P p=que.top();
		que.pop();

		if(p.sc==t) return d[t];

		rep(i,G[p.sc].size())
		{
			edge e=G[p.sc][i];
			if(d[e.to] > d[p.sc]+e.cost)
			{
				d[e.to]=d[p.sc]+e.cost;
				que.push(P(d[e.to],e.to));
			}

		}

	}

}

int main()
{
	cin>>n>>m;
	int a,b,c,d;
	rep(i,m)
	{
		scanf("%d,%d,%d,%d",&a,&b,&c,&d);
		G[a].pb(edge(b,c));
		G[b].pb(edge(a,d));
	}
	scanf("%d,%d,%d,%d",&a,&b,&c,&d);

	printf("%d\n",c-d-dijkstra(a,b)-dijkstra(b,a));



		return 0;
}


