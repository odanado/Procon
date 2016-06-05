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

int n, m;
int x[51], y[51], z[51];
int dp1[51][51][51];
int dp2[51][51][51];
const int INF = 1e9;
int cost(int a, int b, int c) {
    if (dp1[a][b][c] != -INF) return dp1[a][b][c];
    int res = -INF;
    rep(i, b + 1) rep(j, c + 1) {
        if (i == 0 && j == 0)
            res = max(res, z[a]);
        else if (i + j <= 8)
            res = max(res, i * x[a] + j * y[a]);
    }
    return dp1[a][b][c] = res;
}
int dfs(int a, int b, int c) {
    if (a == n) return 0;
    if (dp2[a][b][c] != -INF) return dp2[a][b][c];
    // int res = dfs(a + 1, b, 0) + z[a];
    int res = -INF;

    rep(i, b + 1) { res = max(res, dfs(a + 1, b - i, i) + cost(a, i, c)); }

    return dp2[a][b][c] = res;
}
int main() {
    rep(i, 51) rep(j, 51) rep(k, 51) dp1[i][j][k] = -INF;
    rep(i, 51) rep(j, 51) rep(k, 51) dp2[i][j][k] = -INF;
    cin >> n >> m;
    rep(i, n) cin >> x[i] >> y[i] >> z[i];
    cout << dfs(0, m, 0) << endl;
}
