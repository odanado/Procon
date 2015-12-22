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

struct BipartiteMatching {
    vector<vector<int> > G;
    vector<int> match;
    vector<bool> used;

    int V;
    BipartiteMatching(int V):V(V){
        G.resize(V);
        match.resize(V);
        used.resize(V);
    }

    void add_edge(int u,int v) {
        G[u].push_back(v);
        G[v].push_back(u);
    }

    bool dfs(int v) {
        used[v]=true;
        for(int i=0;i<G[v].size();i++){
            int u=G[v][i];
            int w=match[u];
            if(w<0||!used[w]&&dfs(w)) {
                match[v]=u;
                match[u]=v;
                return true;
            }
        }
        return false;
    }

    int operator() () {
        int res=0;
        match.assign(V,-1);
        for(int v=0;v<V;v++){
            if(match[v]<0) {
                used.assign(V,0);
                if(dfs(v)) res++;
            }
        }
        return res;
    }
};

int N,K;
int R[10004],C[10004];

void solve() {
    BipartiteMatching bm(N*2);
    rep(i,K) bm.add_edge(R[i]-1,N+C[i]-1);

    printf("%d\n",bm());
}

int main() {
    scanf("%d %d",&N,&K);
    rep(i,K) scanf("%d %d",R+i,C+i);
    solve();
    return 0;
}

