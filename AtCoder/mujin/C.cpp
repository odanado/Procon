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
    std::vector<T> par;
    std::vector<T> rank;

public:
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
    bool same(T x, T y) {
        return find(x) == find(y);
    }
};

int N,M;
vector<int> G[20];
vector<int> S;

bool ok() {
    UnionFind<int> uf(N);
    rep(k,2) {
        rep(v,N) if(S[k]>>v&1) {
            for(auto u:G[v]) {
                if(S[k]>>u&1) continue;
                uf.unite(v,u);
            }
        }
    }
    bool ret=true;
    rep(k,2) {
        rep(v,N) rep(u,N) if(v!=u&&(S[k]>>v&1)&&(S[k]>>u&1)) {
            ret&=uf.same(u,v);
        }
    }

    return ret;
}

int main() {
    cin>>N>>M;
    rep(i,M) {
        int x,y;
        cin>>x>>y;
        x--,y--;
        G[x].pb(y);
        G[y].pb(x);
    }
    ll ans=0;
    rep(S1,1<<N) {
        int S2=((1<<N)-1)^S1;
        if(S1==0||S2==0) continue;
        S.clear();
        S.pb(S1);
        S.pb(S2);
        if(ok()) {
            ans++;
        }
    }
    cout<<ans/2<<endl;
    return 0;
}

