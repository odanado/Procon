#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

using namespace std;
using ll = long long;

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

const ll INF=1e18;
const ll MOD=1e9+7;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
using P=pair<int,int>;
struct Edge {
    int to;
    ll cost;
    Edge(int to,int cost) :
        to(to),cost(cost){}
};
void dijk(vector<Edge> *G, ll *d) {
    rep(i,100005) d[i]=INF;

    d[0]=0;
    priority_queue<P,vector<P>,greater<P>> que;
    que.push(P(0,0));
    while(que.size()) {
        P p=que.top(); que.pop();
        int v=p.second;
        for(auto e:G[v]) {
            if(d[e.to]>d[v]+e.cost) {
                d[e.to]=d[v]+e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}
int N,M,T;
int A[100005];
vector<Edge> G[100005];
vector<Edge> rG[100005];

ll d[100005];
ll rd[100005];

int main() {
    rep(i,100005) d[i]=rd[i]=INF;
    cin>>N>>M>>T;
    rep(i,N) cin>>A[i];

    rep(i,M) {
        int a,b,c;
        cin>>a>>b>>c;
        a--,b--;
        G[a].push_back(Edge(b,c));
        rG[b].push_back(Edge(a,c));
    }
    dijk(G,d);
    dijk(rG,rd);
    ll ans=0;
    rep(i,N) {
        ll diff=T-d[i]-rd[i];
        //cout<<d[0][i]<<" + "<<d[i][0]<<": "<<diff<<endl;
        if(diff<0) continue;
        ans=max(ans,diff*A[i]);
    }
    cout<<ans<<endl;

    return 0;
}

