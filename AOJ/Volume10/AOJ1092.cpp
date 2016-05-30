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

using P = pair<int, int>;
int s, d, m;
int f[101];
int dp1[102][302];
int cost[102][302];
int dfs1(int idx, int p) {
    // printf("%d %d\n", idx, p);
    if (idx == d) return 0;
    if (dp1[idx][p] != -INF) return dp1[idx][p];
    int res = 0;

    rep(i, p + 1) { res = max(res, dfs1(idx + 1, p - i) + cost[f[idx]][i]); }
    return dp1[idx][p] = res;
}
int main() {
    while (cin >> s >> d >> m && s) {
        rep(i, 102) rep(j, 302) dp1[i][j] = -INF;
        rep(i, 102) rep(j, 302) cost[i][j] = 0;
        rep(i, s) {
            int k;
            cin >> k;
            vector<int> ws, ps;
            rep(j, k) {
                int w, p;
                cin >> w >> p;
                ws.push_back(w);
                ps.push_back(p);
            }
            rep(a, k) for (int j = m + 1; j >= ps[a]; j--) {
                cost[i][j] = max(cost[i][j], cost[i][j - ps[a]] + ws[a]);
            }
        }
        rep(i, d) cin >> f[i];
        int ans1 = dfs1(0, m);
        int ans2 = 0;

        rep(i, m + 1) {
            if (ans1 == dfs1(0, i)) {
                cout << ans1 << " " << i << endl;
                break;
            }
        }
    }
    return 0;
}
