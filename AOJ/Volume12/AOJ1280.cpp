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
    bool same(T x,T y) {
        return find(x)==find(y);
    }
};
int n,m;
int d;
struct Edge{
    int a,b,w;
    Edge(int a,int b,int w) : a(a),b(b),w(w){}
    Edge(){}
    bool operator<(const Edge& e) const {
        return abs(d-w) < abs(d-e.w);
    }
};


vector<Edge> es;

void solve() {
    int ans=INF;
    rep(i,m) {
        vector<Edge> t=es;
        d=es[i].w;
        sort(all(t));

        //cout<<i<<" ";
        //rep(j,m) printf("%d:%d %d %d, ",j,es[j].a,es[j].b,es[j].w);
        //cout<<endl;

        UnionFind<int> uf(n);
        vector<int> vec;
        vec.pb(es[i].w);
        uf.unite(es[i].a,es[i].b);
        rep(j,m) {
            Edge e=t[j];
            if(es[i].a==e.a&&es[i].b==e.b) continue;
            if(!uf.same(e.a,e.b)) {
                //printf("unit(%d,%d)\n",e.a,e.b);
                uf.unite(e.a,e.b);
                vec.pb(e.w);
            }
        }
        int mini=*min_element(all(vec));
        int maxi=*max_element(all(vec));
        //printf("%d : %d %d\n",i,mini,maxi);
        bool ok=true;
        rep(i,n) rep(j,n) if(!uf.same(i,j)) ok=false;
        if(ok) ans=min(ans,maxi-mini);
    }

    if(ans==INF) cout<<"-1"<<endl;
    else cout<<ans<<endl;
}

int main() {
    while(cin>>n>>m) {
        if(n==0&&m==0) break;
        es.resize(m);
        rep(i,m) {
            int a,b,w;
            cin>>a>>b>>w;
            a--,b--;
            es[i]=Edge(a,b,w);
        }
        if(n-1>m) {
            cout<<"-1"<<endl;
            continue;
        }
        solve();
    }
    return 0;
}

