#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<queue>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int n,m;

struct edge {
public:
	int to,cost,time;
	edge(int b,int cost,int time) {
		this->to = b;
		this->cost = cost;
		this->time = time;
	}
};

typedef pair<int,int> P;

vector<edge> G[3007];

int dijk(int s,int t,int mode) {
	
	priority_queue<P, vector<P> ,greater<P> > que;
	int d[3007];rep(i,3007) d[i]=1000000;
	d[s]=0;
	que.push(P(0,s));

	while (!que.empty())
	{
		P p = que.top(); que.pop();
		int v = p.second;
		if(v==t) break;
		if(d[v] < p.first) continue;

		rep(i,G[v].size()) {
			edge e = G[v][i];
			int cost = mode==0?e.cost:e.time;

			if(d[e.to] > d[v] + cost) {
				d[e.to] = d[v] + cost;
				que.push(P(d[e.to],e.to));
			}

		}
	}
	return d[t];
}

void solve() {
	rep(i,n) {
		int a,b,cost,time;
		cin>>a>>b>>cost>>time;
		G[a].push_back(edge(b,cost,time));
		G[b].push_back(edge(a,cost,time));
	}

	int k;
	cin>>k;
	rep(i,k) {
		int s,t,mode;
		cin>>s>>t>>mode;
		cout<<dijk(s,t,mode)<<endl;
	}

	rep(i,3007) G[i].clear();
}

int main() {
	while (cin>>n>>m)
	{
		if(n+m==0) return 0;
		solve();
	}
	return 0;
}

/* 2014/04/23 AC */