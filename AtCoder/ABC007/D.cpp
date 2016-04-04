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

ll dp[20][2][2];

// idx桁目, 確定してるかどうか, 禁止されているか
ll dfs(int idx, int a, int b, const string &s, ll N) {
    if (idx == s.size()) return b;
    if(dp[idx][a][b]!=-1) return dp[idx][a][b];
    ll ret = 0;
    if (a) {
        rep(i, 10) { ret += dfs(idx + 1, a, b || i == 4 || i == 9, s, N); }
    } else {
        int t = s[idx] - '0';
        rep(i, t + 1) {
            ret += dfs(idx + 1, i < t, b || i == 4 || i == 9, s, N);
        }
    }
    return dp[idx][a][b]=ret;
}

ll A, B;
int main() {
    cin >> A >> B;
    memset(dp, -1, sizeof(dp));
    ll ans = 0;
    ans = dfs(0, 0, 0, to_string(B), B);
    memset(dp, -1, sizeof(dp));
    ans -= dfs(0, 0, 0, to_string(A - 1), A);
    cout << ans << endl;
    return 0;
}
