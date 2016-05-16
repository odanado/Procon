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
int R, C;
P s, g;
string c[51];
int main() {
    cin >> R >> C;
    cin >> s.first >> s.second;
    cin >> g.first >> g.second;
    s.first--;
    s.second--;
    g.first--;
    g.second--;
    rep(i, R) cin >> c[i];
    map<P, int> dp;
    queue<P> que;

    que.push(s);
    dp[s] = 0;
    while (que.size()) {
        P p = que.front();
        que.pop();
        rep(k, 4) {
            int ny = p.first + dy[k];
            int nx = p.second + dx[k];
            if (ny < 0 || ny >= R) continue;
            if (nx < 0 || nx >= C) continue;
            if (c[ny][nx] != '.') continue;
            if (dp.count(P(ny, nx))) continue;
            dp[P(ny, nx)] = dp[p] + 1;
            que.push(P(ny, nx));
        }
    }
    cout << dp[g] << endl;

    return 0;
}
