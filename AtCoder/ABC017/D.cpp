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

// Verified
// http://code-festival-2015-final-open.contest.atcoder.jp/tasks/codefestival_2015_final_d
// http://judge.u-aizu.ac.jp/onlinejudge/cdescription.jsp?cid=RitsCamp16Day3&pid=F

template <class T>
struct StarrySkyTree {
    using int_type = T;
    vector<T> data;
    vector<T> lazy;
    int N;
    StarrySkyTree(int n) {
        N = 1;
        while (N < n) N <<= 1;
        data.assign(2 * N - 1, 0);
        lazy.assign(2 * N - 1, 0);
    }
    // [a,b)
    void add(int a, int b, int_type val) { add(a, b, val, 0, 0, N); }
    int_type get(int a, int b) { return get(a, b, 0, 0, N); }

    void add(int a, int b, int_type val, int k, int l, int r) {
        if (r <= a || b <= l) return;
        if (a <= l && r <= b) {
            lazy[k] += val;
            return;
        }
        add(a, b, val, k * 2 + 1, l, (l + r) / 2);
        add(a, b, val, k * 2 + 2, (l + r) / 2, r);
        data[k] = max(data[k * 2 + 1] + lazy[k * 2 + 1],
                      data[k * 2 + 2] + lazy[k * 2 + 2]);
    }

    int_type get(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return -INF;
        if (a <= l && r <= b) return data[k] + lazy[k];
        auto lval = get(a, b, k * 2 + 1, l, (l + r) / 2);
        auto rval = get(a, b, k * 2 + 2, (l + r) / 2, r);
        return max(lval, rval) + lazy[k];
    }
};

int N, M;
int f[100005];

void solve() {
    set<int> S;
    StarrySkyTree<ll> sst(100005);
    sst.add(0, 1, 1);
    int s = 1, t = 2;
    while (s < N + 1) {
        S.insert(f[s]);
        while (t < N + 1) {
            if (S.count(f[t])) break;
            S.insert(f[t]);
            t++;
        }
        ll x = sst.get(s - 1, s);
        x = (x % MOD + MOD) % MOD;
        sst.add(s, t, x);

        // cout << s-1 << ": ";
        // rep(k, N + 1) cout << sst.get(k, k + 1) << " ";
        // printf("range(%d,%d) add(%lld)\n",s,t,x);

        S.erase(f[s]);
        s++;
        t = max(t, s + 1);
    }
    ll ans = sst.get(N, N + 1);
    ans = (ans % MOD + MOD) % MOD;
    cout << ans << endl;
}

int main() {
    cin >> N >> M;
    rep(i, N) cin >> f[i + 1];
    solve();
    return 0;
}
