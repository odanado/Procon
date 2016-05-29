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

template <class T>
struct SegTree {
    typedef T int_type;
    static const size_t MAX_N = 1 << 17;
    static const int_type INIT_VAL = 0;
    int_type data[2 * MAX_N - 1];
    size_t n;
    SegTree(size_t n__) {
        n = 1;
        while (n < n__) n *= 2;
        rep(i, 2 * n - 1) data[i] = INIT_VAL;
    }
    void update(size_t k, int_type a) {
        k += n - 1;
        data[k] = a;
        while (k > 0) {
            k = (k - 1) / 2;
            data[k] = max(data[k * 2 + 1], data[k * 2 + 2]);
        }
    }

    int_type query(size_t a, size_t b, size_t k, size_t l, size_t r) {
        if (r <= a || b <= l) return INIT_VAL;
        if (a <= l && r <= b)
            return data[k];
        else {
            int_type vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
            int_type vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
            return max(vl, vr);
        }
    }
    int_type query(size_t a, size_t b) { return query(a, b, 0, 0, n); }
};

int N;
vector<int> H, W;
int main() {
    cin >> N;
    H.resize(N);
    W.resize(N);
    rep(i, N) { cin >> W[i] >> H[i]; }
    SegTree<int> segTree(100005);

    vector<pair<int, int>> vec;
    rep(i, N) vec.push_back(make_pair(W[i], -H[i]));
    sort(all(vec));
    rep(i, N) W[i] = vec[i].first, H[i] = -vec[i].second;

    rep(i, N) {
        int t = segTree.query(0, H[i]);
        segTree.update(H[i], t + 1);
    }

    cout << segTree.query(0, 100005) << endl;

    return 0;
}
