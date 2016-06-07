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
#include <unordered_map>

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

vector<ll> f(ll N) {
    vector<ll> vs;
    for (ll i = 2; i * i <= N; i++) {
        while (N % i == 0) {
            vs.push_back(i);
            N /= i;
        }
    }
    if (N != 1) vs.push_back(N);
    return vs;
}

map<tuple<int, ll, ll, ll>, ll> dp;

ll dfs(int idx, ll t1, ll t2, ll t3, vector<ll> &vs) {
    if (idx == vs.size()) return t1 + t2 + t3 - 3;
    auto s = tie(idx, t1, t2, t3);
    if (dp.count(s)) return dp[s];
    ll res = dfs(idx + 1, t1 * vs[idx], t2, t3, vs);
    res = min(res, dfs(idx + 1, t1, t2 * vs[idx], t3, vs));
    res = min(res, dfs(idx + 1, t1, t2, t3 * vs[idx], vs));

    return dp[s] = res;
}

int main() {
    ll N;
    cin >> N;
    auto vs = f(N);
    ll ans = 0;
    /*
    while (vs.size()) {
        auto it = vs.begin();
        rep(i, 3) {
            if (it == vs.end()) break;
            t[i] *= *it;
            it = vs.erase(it);
        }
        reverse(all(vs));
    }
    rep(i, 3) ans += t[i] - 1;
    */
    ans = dfs(0, 1, 1, 1, vs);
    cout << ans << " " << N - 1 << endl;
    return 0;
}
