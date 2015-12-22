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
 
#include <vector>
struct UnionFind {
    int size_;
    std::vector<int> par;
    std::vector<int> rank;
    UnionFind(int size_) : size_(size_) {
        par.resize(size_);
        rank.resize(size_);
 
        for(int i=0; i<size_; i++) {
            par[i]  = i;
            rank[i] = 0;
        }
    }
 
    int find(int x) {
        return par[x] == x ? x : par[x] = find(par[x]);
    }
    void unite(int x,int y) {
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
    bool same(int x,int y) {
        return find(x)==find(y);
    }
};
 
int n,m;
 
typedef pair<int,P> Pi;
int kruskal(int v,const vector<Pi> &vec) {
    UnionFind uf(n);
    int ret=0;
    rep(i,vec.size()) {
        Pi pi=vec[i];
        if(pi.sc.fr==v||pi.sc.sc==v) continue;
        if(!uf.same(pi.sc.fr,pi.sc.sc)) {
            uf.unite(pi.sc.fr,pi.sc.sc);
            ret+=pi.fr;
        }
    }
 
    return ret;
}
 
void solve() {
    vector<Pi> vec;
    int s=0;
    rep(i,m) {
        int x,y,c;
        cin>>x>>y>>c;
        vec.pb(Pi(c,mp(x,y)));
        s+=c;
    }
    int ans=INF;
    sort(all(vec),[](Pi p1,Pi p2){return p1.fr>p2.fr;});
    rep(i,n) {
        int t=s;
        rep(j,vec.size()) if(vec[j].sc.sc==i) t+=vec[j].fr;
        ans=min(ans,t-kruskal(i,vec));
    }
    cout<<ans<<endl;
 
}
 
int main() {
    while(cin>>n>>m) {
        if(!n) break;
        solve();
    }
    return 0;
}
