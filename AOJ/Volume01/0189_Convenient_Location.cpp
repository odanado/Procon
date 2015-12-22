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
#define FOR(itr,data) for(__typeof((data).begin()) itr=(data).begin();itr!=(data).end();++itr)

typedef unsigned long long UInt64;
typedef long long Int64;

const int INF=100000000;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

using namespace std;

typedef pair<int ,int > P;

int n;

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

int d[10];
vector<edge> G[10];

int dijkstra(int s)
{
	priority_queue<P,vector<P>, greater<P> > que;
	fill(d,d+10,INF);
	d[s]=0;
	que.push(P(0,s));

	while(que.size())
	{
		P p=que.top();que.pop();

		rep(i,G[p.sc].size())
		{
			edge e=G[p.sc][i];
			if(d[e.to]>d[p.sc]+e.cost)
			{
				d[e.to]=d[p.sc]+e.cost;
				que.push(P(d[e.to],e.to));
			}
		
		}
	}
	int res=0;
	rep(i,10)
	{
		if(d[i]!=INF)
			res+=d[i];
	}
	return res;
}


void solve()
{
	rep(i,10) G[i].clear();

	int mi=INF;
	int ans;
	set<int> city;

	rep(i,n)
	{
		int a,b,c;
		cin>>a>>b>>c;
		G[a].pb(edge(b,c));
		G[b].pb(edge(a,c));
		city.insert(a);
		city.insert(b);
	}

	FOR(it,city)
	{
		int tmp=dijkstra(*it);
		if(tmp<mi)
		{
			mi=tmp;
			ans=*it;
		}
	}
	cout<<ans<<" "<<mi<<endl;
}




int main()
{
	while(cin>>n)
	{
		if(!n) return 0;
		solve();


	}
		return 0;
}


