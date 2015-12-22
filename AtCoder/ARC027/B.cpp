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

int n;
string s1,s2;
ll ans;
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
};

bool check(UnionFind<int> &uf, char c) {
    rep(i,10) {
        if(uf.find(c) == uf.find(i+'0')) return false;
    }
    return true;
}

bool used[130];
int main() {
    ans = 1;
    cin>>n;
    cin>>s1;
    cin>>s2;
    UnionFind<int> uf(130);
    rep(i,n) {
        uf.unite(s1[i],s2[i]);
    }

    rep(i,26) {
        char c = 'A'+i;
        if(check(uf,c)&&(s1.find(c)!=string::npos || s2.find(c)!=string::npos)) {
            if(used[uf.find(c)]) continue;
            used[uf.find(c)] = true;
            if(s1[0]!=c && s2[0]!=c) {
                ans *= 10;
            }
            else {
                ans *= 9;
            }
        }
    }

    cout<<ans<<endl;



    return 0;
}

