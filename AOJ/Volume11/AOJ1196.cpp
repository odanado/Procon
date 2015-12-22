#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
int n;
struct Edge {
    int to,cost;
};
vector<Edge> G[1003];
long long dfs(int v,int u,int &t) {
    long long ret=0;
    rep(i,G[v].size()) {
        Edge e=G[v][i];
        if(u==e.to) continue;
        if(G[e.to].size()==1) {
        }
        else {
            ret+=dfs(e.to,v,t)+e.cost*2;
            t=v;
        }
    }

    return ret;
}
void solve() {

    rep(i,1003) G[i].clear();
    long long ans=1e18;
    int p[1003],d[1003];
    rep(i,n-1) cin>>p[i];
    rep(i,n-1) cin>>d[i];
    rep(i,n-1) p[i]--;

    rep(i,n-1) {
        G[i+1].push_back(Edge{p[i],d[i]});
        G[p[i]].push_back(Edge{i+1,d[i]});
    }
    rep(i,n) {
        if(G[i].size()==1) continue;
        int v;
        long long t=dfs(i,-1,v);
        t-=d[i];
        if(G[v].size()!=1) t-=d[v];
        cout<<i<<", "<<v<<endl;
        ans=min(ans,t);
    }
    rep(i,n-1) ans+=d[i];
    cout<<ans<<endl;
}


int main() {
    while(cin>>n) {
        if(!n) break;
        solve();
    }
}
