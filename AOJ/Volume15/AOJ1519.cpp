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
struct UnionFind {
    int size_;
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
    bool same(T x,T y) {
        return find(x)==find(y);
    }
};
int n;
int a[100005];
int main() {
    int q;
    cin>>n>>q;
    UnionFind<int> uf(n+1);
    while(q-->0) {
        string s;cin>>s;
        int A,B,C;
        if(s=="IN") {
            cin>>A>>B>>C;
            if(a[B]-a[A]!=C) {
                if(a[B]<a[A]) a[B]=a[A]+C;
                else a[A]=a[B]-C;
            }
            a[A]+=C;
            a[B]+=C;
            uf.unite(A,B);
        }
        else {
            cin>>A>>B;
            int ret=a[B]-a[A];
            if(!uf.same(A,B)) cout<<"WARNING"<<endl;
            else cout<<ret<<endl;
        }
    }
    return 0;
}

