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

int N;
vector<vector<int>> adj;
ll dp[100005][2];
ll dfs(int pre, int v, int color) {
    ll res = 1;
    if (dp[v][color] != -1) return dp[v][color];
    if (color) {
        for (auto next : adj[v])
            if (pre != next) {
                res *= dfs(v, next, 0);
                res %= MOD;
            }
    } else {
        for (auto next : adj[v])
            if (pre != next) {
                res *= (dfs(v, next, 0) + dfs(v, next, 1)) % MOD;
                res %= MOD;
            }
    }
    return dp[v][color] = res;
}
int main() {
    memset(dp, -1, sizeof(dp));
    cin >> N;
    adj.resize(N);
    rep(i, N - 1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout << (dfs(-1, 0, 0) + dfs(-1, 0, 1)) % MOD << endl;
    return 0;
}
