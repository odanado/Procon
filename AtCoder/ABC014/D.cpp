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
int N;
vector<int> G[100005];
int root;
class LCA {
    int root;
    const int MAX_V;
    const int MAX_LOG_V;
    vector<vector<int> > parent;
    
    void dfs(const vector<int> *G,int v,int p,int d) {
        parent[0][v] = p;
        depth[v] = d;
        for(int i=0;i<G[v].size();i++) {
            if(G[v][i]!=p) dfs(G,G[v][i],v,d+1);
        }
    
    }

public:
    LCA(int root, const int MAX_V) :
        root(root), MAX_V(MAX_V), MAX_LOG_V(log2(MAX_V)+1) {

            depth.resize(MAX_V);
            parent.resize(MAX_LOG_V);
            for(int i=0;i<parent.size();i++) {
                parent[i].resize(MAX_V);
            }
        }

    void init(const vector<int> *G,int V) {
        dfs(G,root,-1,0);
        for(int k=0;k<MAX_LOG_V-1;k++) {
            for(int v=0;v<V;v++) {
                if(parent[k][v]<0) parent[k+1][v] = -1;
                else parent[k+1][v] = parent[k][parent[k][v]];
            }
        }
    }

    int exec(int u,int v) {
        if(depth[u] > depth[v]) swap(u,v);
        for(int k=0;k<MAX_LOG_V;k++) {
            if((depth[v]-depth[u])>>k &1) {
                v = parent[k][v];
            }
        }
        if(u == v) return u;
        for(int k=MAX_LOG_V-1;k>=0;k--) {
            if(parent[k][u]!=parent[k][v]) {
                v=parent[k][v];
                u=parent[k][u];
            }
        }
        return parent[0][u];
    }
    vector<int> depth;

};

int main() {
    cin>>N;
    int maxi = 0;
    rep(i,N-1) {
        int x,y;
        cin>>x>>y;
        x--;y--;
        G[x].pb(y);
        G[y].pb(x);
        root = x;
    }
    LCA lca = LCA(root,100005);
    lca.init(G,N);
    int Q;
    cin>>Q;
    rep(i,Q) {
        int a,b;
        cin>>a>>b;
        a--;b--;
        int v = lca.exec(a,b);
        int ans = lca.depth[a]+lca.depth[b];
        ans -= lca.depth[v]*2;
        cout<<ans+1<<endl;

    }
    return 0;
}

