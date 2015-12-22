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
            par[i] = i;
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
        return find(x) == find(y);
    }
};
int n;
struct Sphere {
    double x,y,z,r;
};
struct Edge {
    int from;
    int to;
    double cost;

    bool operator<(const Edge &rth) const {
        return cost < rth.cost;
    }
};
double pow2(double x) {
    return x*x;
}
double dist(Sphere s1, Sphere s2) {
    double t;
    t=pow2(s1.x-s2.x);
    t+=pow2(s1.y-s2.y);
    t+=pow2(s1.z-s2.z);
    t=sqrt(t);

    t=t-s1.r-s2.r;

    if(t<0) t=0;
    return t;
}
void solve() {
    UnionFind<int> uf(102);
    vector<Edge> edges;
    Sphere sphere[102];
    rep(i,n) {
        double x,y,z,r;
        cin>>x>>y>>z>>r;
        sphere[i]={x,y,z,r};
    }
    rep(i,n) rep(j,n) if(i!=j) {
        double d=dist(sphere[i],sphere[j]);
        edges.push_back({i,j,d});
    }

    sort(all(edges));
    double ans=0;

    rep(i,edges.size()) {
        Edge e = edges[i];
        if(!uf.same(e.from,e.to)) {
            ans+=e.cost;
            uf.unite(e.from,e.to);
        }
    }

    printf("%.3f\n",ans);
}
int main() {
    while(cin>>n) {
        if(n==0) break;
        solve();
    }
    return 0;
}

