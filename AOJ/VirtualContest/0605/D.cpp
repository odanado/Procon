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
#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N;
struct Edge {
    int to, cost;
    Edge(int to, int cost) : to(to), cost(cost) {}
};
const int INF = 1e9;
using P = pair<int, int>;
vector<Edge> G[21];
int dp[21][21];

void solve() {
    rep(i, 21) rep(j, 21) dp[i][j] = INF;
    rep(i, 21) dp[i][i] = 0;
    rep(i, 21) G[i].clear();

    rep(i, N - 1) {
        int a, b, t;
        cin >> a >> b >> t;
        a--, b--;
        G[a].push_back(Edge(b, t));
        G[b].push_back(Edge(a, t));
        dp[a][b] = t;
        dp[b][a] = t;
    }
    rep(k, N) rep(i, N) rep(j, N) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
    int ans = 0;
    rep(i, N) {
        for (auto e : G[i]) {
            if ((i == 0 || G[i].size() != 1) &&
                (e.to == 0 || G[e.to].size() != 1)) {
                // printf("debug: %d %d %d\n", i, e.to, e.cost);
                ans += e.cost;
            }
        }
    }
    // cout << ans << endl;
    int maxi = 0;
    rep(i, N) {
        if (G[i].size() == 1) {
            maxi = max(maxi, dp[0][G[i][0].to]);
        }
    }
    ans -= maxi;
    cout << ans << endl;
}
int main() {
    while (cin >> N) {
        if (N == 0) break;
        solve();
    }
}
