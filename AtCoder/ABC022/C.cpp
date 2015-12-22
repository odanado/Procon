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

struct Edge {
    int to,cost;
    int id;
    Edge(int to,int cost,int id) :
        to(to),cost(cost),id(id){}
};

vector<Edge> G[302];
int n,m;

int dijk(int s,int t,int id) {
    int d[302];
    rep(i,302) d[i]=INF;
    d[s]=0;
    priority_queue<P,vector<P>,greater<P> > que;
    que.push(P(0,s));

    while(que.size()) {
        P p=que.top(); que.pop();
        int cost=p.fr;
        int v=p.sc;

        rep(i,G[v].size()) {
            Edge e=G[v][i];
            if(id==e.id) continue;
            if(d[e.to]>d[v]+e.cost) {
                d[e.to]=d[v]+e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }

    return d[t];
}

int main() {
    cin>>n>>m;
    int id=0;
    rep(i,m) {
        int u,v,l;
        cin>>u>>v>>l;
        u--,v--;
        G[u].pb(Edge(v,l,id));
        G[v].pb(Edge(u,l,id));
        id++;
    }

    int ans=INF;
    rep(i,G[0].size()) {
        Edge e=G[0][i];
        int t=dijk(e.to,0,e.id)+e.cost;
        //printf("%d->%d %d : %d\n",e.to,0,e.id,t);

        ans=min(ans, t);
    }
    if(ans==INF) ans=-1;
    cout<<ans<<endl;

    return 0;
}

