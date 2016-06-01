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
P dp1[102][302];
int cost[102][302];
P dfs1(int idx, int p) {
    // printf("%d %d\n", idx, p);
    if (idx == d) return P(0, 0);
    if (dp1[idx][p] != P(-INF, -INF)) return dp1[idx][p];
    auto res = P(0, 0);

    rep(i, p + 1) {
        auto t = dfs1(idx + 1, p - i);
        t.first += cost[f[idx]][i];
        t.second -= i;
        res = max(res, t);
    }
    return dp1[idx][p] = res;
}
int main() {
    while (cin >> s >> d >> m && s) {
        rep(i, 102) rep(j, 302) dp1[i][j] = P(-INF, -INF);
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
        auto ans1 = dfs1(0, m);
        cout << ans1.first << " " << -ans1.second << endl;
    }
    return 0;
}
