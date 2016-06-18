#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
using ll = long long;

#define all(c) (c).begin(), (c).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

const ll INF = 1e9;
const ll MOD = 1e9 + 7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

template <typename T>
class UnionFind {
    int size_;
    std::vector<T> par;
    std::vector<T> rank;
    std::vector<T> sz;

 public:
    UnionFind(int size_) : size_(size_) {
        par.resize(size_);
        rank.resize(size_);
        sz.resize(size_);

        for (int i = 0; i < size_; i++) {
            par[i] = i;
            rank[i] = 0;
            sz[i] = 1;
        }
    }

    T find(T x) { return par[x] == x ? x : par[x] = find(par[x]); }
    void unite(T x, T y) {
        x = find(x);
        y = find(y);
        if (x == y) return;

        if (rank[x] < rank[y]) {
            par[x] = y;
            sz[y] += sz[x];
        } else {
            par[y] = x;
            sz[x] += sz[y];
            if (rank[x] == rank[y]) rank[x]++;
        }
    }
    bool same(T x, T y) { return find(x) == find(y); }
    int size(T x) { return sz[find(x)]; }
};

int N, M;

int main() {
    ios::sync_with_stdio(false);
    vector<tuple<int, int, int, int>> vec;
    cin >> N >> M;
    rep(i, M) {
        int a, b, y;
        cin >> a >> b >> y;
        vec.emplace_back(-y, 1, a, b);
    }
    int Q;
    cin >> Q;
    rep(i, Q) {
        int v, w;
        cin >> v >> w;
        vec.emplace_back(-w, 0, v, i);
    }
    UnionFind<int> uf(N + 1);
    sort(all(vec));
    vector<int> ans(Q);
    for (auto x : vec) {
        if (get<1>(x) == 1) {
            // printf("unite(%d, %d)\n", get<2>(x), get<3>(x));
            uf.unite(get<2>(x), get<3>(x));
        } else {
            // printf("query(%d, %d)\n", get<2>(x), get<3>(x));
            ans[get<3>(x)] = uf.size(get<2>(x));
        }
    }
    for (auto x : ans) cout << x << endl;
    return 0;
}
