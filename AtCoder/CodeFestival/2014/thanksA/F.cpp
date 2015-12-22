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
template<typename T>
class UnionFind {
    int size_;

    public:
    std::vector<T> par;
    std::vector<T> rank;
    UnionFind(int size_) : size_(size_) {
        par.resize(size_);
        rank.resize(size_);

        for(int i=0; i<size_; i++) {
            par[i]  = i;
            rank[i] = 0;
        }
    }

    T find(T x) {
        return par[x] == x ? x : par[x] = find(par[x]);
    }
    void unite(T x,T y) {
        x = find(x);
        y = find(y);
        if(x == y) return;

        if(rank[x] < rank[y]) {
            par[x] = y;
        }
        else {
            par[y] = x;
            if(rank[x] == rank[y]) rank[x]++;
        }
    }
};

int N,M;
int a[55],b[55];
vector<int> G[55];
int dfs(int s,int t) {
    queue<P> que;
    que.push(P(s,0));
    bool flag[55] = {};

    while(que.size()) {
        P p = que.front();
        que.pop();
        int v = p.fr;
        if(flag[v]) continue;
        flag[v] = true;
        if(p.fr==t) return 1;
        rep(i,G[v].size()) {
            int e = G[v][i];
            que.push(P(e,p.sc+1));
        }

    }

    return 0;
}
int main() {
    cin>>N>>M;
    rep(i,M) {
        cin>>a[i]>>b[i];
        G[a[i]].pb(b[i]);
    }
    int ans = 0;
    rep(i,N+1) {
        if(i==0) continue;
        if(dfs(i,1)==1) ans++;
    }
    cout<<ans<<endl;
    return 0;
}

