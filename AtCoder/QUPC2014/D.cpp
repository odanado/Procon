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

const int INF=1000000007;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

using namespace std;

typedef pair<int ,int > P;

struct edge {
    int to,cost;
    edge(int _to,int _cost) {
        to=_to;
        cost=_cost;
    }
};
int n,m,k;
int start,goal;
int x[107],f[107];

vector<edge> G[30007];
int d[2][30007];

void dijkstra(int s,int id) {
    //vector<int> d;
    rep(i,n) d[id][i]=INF;
    d[id][s]=0;

    priority_queue<P,vector<P>, greater<P> > que;
    que.push(P(0,s));

    while(!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.sc;
        int cost = p.fr;
        if(d[id][v] < cost) continue;
        for(int i=0;i<G[v].size();i++) {
            edge e = G[v][i];
            if(d[id][e.to] > d[id][v] + e.cost) {
                d[id][e.to] = d[id][v]+e.cost;
                que.push(P(d[id][e.to],e.to));
            }
        }
    }
    
}
inline int conv(int l) {
    if(l<=0) return 0;
    if(l==INF) return INF;
    rep(i,k) {
        if(x[i]<=l&&l<x[i+1]) return f[i];
    }
}

int main() {
    cin>>n>>m>>k;
    cin>>start>>goal;
    rep(i,m) {
        int a,b,c;
        cin>>a>>b>>c;
        G[a].pb(edge(b,c));
        G[b].pb(edge(a,c));
    }
    rep(i,k) cin>>x[i]>>f[i];
    x[k]=INF;
    dijkstra(start,0);
    dijkstra(goal,1);
    //頂点の取り方総当り

    int ans = conv(d[0][goal]);

    //start -> i -> goal
    rep(i,n) {
        ans=min(ans,conv(d[0][i])+conv(d[1][i]));
    }

    cout<<ans<<endl;
    return 0;
}



