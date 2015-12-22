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

struct LCA {
    int N;
    int root;
    int log2_n;
    vector<vector<int>> parent;
    vector<int> depth;
    vector<vector<int>> G;
    LCA(int N,int root=0) : N(N), root(root) {
        log2_n = log2(N) + 1;
        parent.resize(log2_n);
        rep(i,log2_n) parent[i].resize(N);
        depth.resize(N);
        G.resize(N);
    }
    void add_edge(int v,int u) {
        G[v].pb(u);
    }
    void init() {
        dfs(root,-1,0);
        rep(k,log2_n-1) rep(v,N) {
            if(parent[k][v]<0) parent[k+1][v]=-1;
            else parent[k+1][v]=parent[k][parent[k][v]];
        }
    }
    void dfs(int v,int p,int d) {
        parent[0][v]=p;
        depth[v]=d;
        rep(i,G[v].size()) {
            if(G[v][i]!=p) dfs(G[v][i],v,d+1);
        }
    }
    int operator()(int u,int v) {
        if(depth[u]>depth[v]) swap(u,v);
        rep(k,log2_n) {
            if((depth[v]-depth[u])>>k&1) {
                v=parent[k][v];
            }
        }
        if(v==u) return u;

        for(int k=log2_n-1;k>=0;k--) {
            if(parent[k][u]!=parent[k][v]) {
                u=parent[k][u];
                v=parent[k][v];
            }
        }
        return parent[0][u];
    }
    int dist(int v,int u) {
        int a=operator()(v,u);
        return depth[v] - depth[a] + depth[u] - depth[a];
    }
};

int main() {
    int N;
    cin>>N;
    LCA lca(N);
    int root=1e8;
    rep(i,N-1) {
        int x,y;
        cin>>x>>y; x--,y--;
        root=min(root,x);
        lca.add_edge(x,y);
        lca.add_edge(y,x);
    }
    lca.root=root;
    lca.init();
    int Q;cin>>Q;
    while(Q-->0) {
        int a,b;
        cin>>a>>b; a--,b--;
        int ans = lca.dist(a,b) + 1;
        cout<<ans<<endl;
    }
    return 0;
}

