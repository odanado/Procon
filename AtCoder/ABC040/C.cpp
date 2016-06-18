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

int n;
ll a[100005];
ll dp[100005];
ll dfs(int idx) {
    if (idx + 1 == n) return 0;
    if (dp[idx] != -1) return dp[idx];
    ll res = dfs(idx + 1) + abs(a[idx] - a[idx + 1]);
    if (idx + 2 < n) res = min(res, dfs(idx + 2) + abs(a[idx] - a[idx + 2]));
    return dp[idx] = res;
}
int main() {
    cin >> n;
    rep(i, n) cin >> a[i];
    memset(dp, -1, sizeof(dp));
    cout << dfs(0) << endl;

    return 0;
}
