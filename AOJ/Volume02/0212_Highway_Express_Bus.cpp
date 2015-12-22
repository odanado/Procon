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
typedef pair<P,int> Pi;

class edge
{
	public:
		int to;
		int cost;
		int ticket;

		edge(int _to,int _cost)
		{
			to=_to;
			cost=_cost;

		}
};

int c,n,m,s,t;

int solve()
{
	int d[107][11];
	vector<edge> G[107];

	int ans=INF;
	rep(i,11)
		fill(d[i],d[i]+107,INF);

	d[s][0]=0;

	priority_queue<Pi, vector<Pi>, greater<Pi> > que;

	rep(i,m)
	{
		int a,b,f;
		cin>>a>>b>>f;
		G[a].pb(edge(b,f));
		G[b].pb(edge(a,f));
	}

	que.push(Pi(P(0,s),c));
	while(que.size())
	{
		Pi pi=que.top();
		que.pop();
		int v=pi.fr.sc;
		int cost=pi.fr.fr;
		int ticket=pi.sc;

		if(v==t)
			ans=min(ans,d[v][ticket]);

		rep(i,G[v].size())
		{
			edge e=G[v][i];

			if(d[e.to][ticket]>d[v][ticket]+e.cost)
			{
				d[e.to][ticket]=d[v][ticket]+e.cost;
				que.push(Pi(P(d[e.to][ticket],e.to),ticket));
			}

			if(ticket!=0&&d[e.to][ticket-1]>d[v][ticket]+e.cost/2)
			{
				d[e.to][ticket-1]=d[v][ticket]+e.cost/2;
				que.push(Pi(P(d[e.to][ticket-1],e.to),ticket-1));
			}

		}

	}
	rep(i,c)
		ans=min(ans,d[t][i]);
	return ans;
}

int main()
{

	while(cin>>c>>n>>m>>s>>t)
	{
		if(!c&&!n&&!m&&!s&&!t)
			break;
		printf("%d\n",solve());
	}
		


		return 0;
}

