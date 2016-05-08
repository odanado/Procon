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

int H, W;
int a[1003][1003];
ll dp[1003][1003];
ll dfs(int y, int x) {
    ll &res = dp[y][x];
    if (res != -1) return res;
    res = 1;
    rep(k, 4) {
        int ny = y + dy[k];
        int nx = x + dx[k];
        if (ny < 0 || H <= ny) continue;
        if (nx < 0 || W <= x) continue;
        if (a[y][x] >= a[ny][nx]) continue;
        res += dfs(ny, nx);
        res %= MOD;
    }
    return res;
}
vector<tuple<int, int, int>> vec;
int main() {
    cin >> H >> W;
    rep(i, H) rep(j, W) cin >> a[i][j];
    rep(i, H) rep(j, W) vec.emplace_back(a[i][j], i, j);
    memset(dp, -1, sizeof(dp));
    sort(all(vec));
    ll ans = 0;
    for (auto &e : vec) {
        ans += dfs(get<1>(e), get<2>(e));
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
