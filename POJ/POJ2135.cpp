#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <climits>

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

const int INF=100000000;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
using namespace std;
typedef pair<int ,int > P;
typedef long long ll;

struct MinumumCostFlow {
    static const int MAX_V=10004;
    typedef pair<int,int> P;
    struct Edge {
        int to,cost,cap,rev;
        Edge(int to=0,int cap=0,int cost=0,int rev=0) :
            to(to),cap(cap),cost(cost),rev(rev) {}
    };

    int V;
    vector<Edge> G[MAX_V];
    int h[MAX_V];
    int dist[MAX_V];
    int prev_v[MAX_V],prev_e[MAX_V];

    void add_edge(int from,int to, int cap,int cost) {
        G[from].push_back(Edge(to,cap,cost,G[to].size()));
        G[to].push_back(Edge(from,0,-cost,G[from].size()-1));
    }

    int operator()(int s,int t,int f) {
        int res=0;
        fill(h,h+V,0);

        while(f>0) {
            priority_queue<P,vector<P>, greater<P> > que;
            fill(dist,dist+V,INF);
            dist[s]=0;
            que.push(P(0,s));

            while(que.size()) {
                P p=que.top(); que.pop();
                int v=p.second;
                if(dist[v]<p.first) continue;
                rep(i,G[v].size()) {
                    Edge &e=G[v][i];
                    if(e.cap>0 && dist[e.to]>dist[v]+e.cost+h[v]-h[e.to]) {
                        dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];
                        prev_v[e.to]=v;
                        prev_e[e.to]=i;
                        que.push(P(dist[e.to],e.to));
                    }
                }
            }
            if(dist[t]==INF) return -1;
            rep(v,V) h[v]+=dist[v];

            int d=f;
            for(int v=t;v!=s;v=prev_v[v]) {
                d=min(d,G[prev_v[v]][prev_e[v]].cap);
            }
            f-=d;
            res+=d*h[t];

            for(int v=t;v!=s;v=prev_v[v]) {
                Edge &e=G[prev_v[v]][prev_e[v]];
                e.cap-=d;
                G[v][e.rev].cap+=d;
            }

        }

        return res;
    }

};


int N,M;
int main() {
    MinumumCostFlow min_cost_flow;
    scanf("%d %d",&N,&M);
    int s=0,t=N-1;
    min_cost_flow.V=N;
    rep(i,M) {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        min_cost_flow.add_edge(a-1,b-1,1,c);
        min_cost_flow.add_edge(b-1,a-1,1,c);
    }
    printf("%d\n",min_cost_flow(s,t,2));
    return 0;
}

