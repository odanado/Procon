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

int N, K;
double dp[1003][1003][2];
double dfs(int i, int j, int b) {
    if (i == N) return b;
    if (dp[i][j][b] != -1) return dp[i][j][b];
    // maxではない
    double p1 = 1.0 * i / (i + 1) * dfs(i + 1, j, b);
    // maxだから食べると食べない両方を試す
    double p2, p3;
    if (j == K) {
        // もう食べられない
        p2 = 0.0;
        p3 = 1.0 / (i + 1) * dfs(i + 1, j, 0);
    } else {
        // まだ食べられる
        p2 = 1.0 / (i + 1) * dfs(i + 1, j + 1, 1);
        p3 = 1.0 / (i + 1) * dfs(i + 1, j, 0);
    }
    return dp[i][j][b] = p1 + max(p2, p3);
}
int main() {
    rep(i, 1003) rep(j, 1003) dp[i][j][0] = dp[i][j][1] = -1;
    cin >> N >> K;
    double ans = dfs(0, 0, 0);
    printf("%.9f\n", ans);
    return 0;
}
