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
#include <tuple>
#include <complex>

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
using State = tuple<P, int>;

P miniBishop[2] = {P(1, 1), P(1, -1)};
P kNight[4] = {P(2, 1), P(1, 2), P(-1, 2), P(-2, 1)};

int H, W;
bool valid(int x, int y) {
    if (x < 0 || y < 0) return false;
    if (x >= W || y >= H) return false;
    return true;
}
string maze[502];
map<State, int> dp;
queue<State> que;
void func(int y, int x, int dy, int dx, State &t) {
    // printf("debug: %d %d %d %d\n",y, x, dy,dx);
    int ny = y + dy;
    int nx = x + dx;
    if (valid(nx, ny)) {
        auto next = t;
        get<0>(next) = P(ny, nx);
        if (maze[ny][nx] == 'R') get<1>(next) ^= 1;
        if (!dp.count(next)) {
            dp[next] = dp[t] + 1;
            que.push(next);
        }
    }
}

int get(State s) {
    if (dp.count(s)) return dp[s];
    return INF;
}

int main() {
    cin >> H >> W;
    rep(i, H) cin >> maze[i];
    P s, g;
    rep(i, H) rep(j, W) if (maze[i][j] == 'S') s = P(i, j);
    rep(i, H) rep(j, W) if (maze[i][j] == 'G') g = P(i, j);

    que.push(make_tuple(s, 0));
    dp[make_tuple(s, 0)] = 0;

    while (que.size()) {
        auto t = que.front();
        que.pop();
        P p = get<0>(t);
        // printf("debug: %d %d %d\n", p.first, p.second, get<1>(t));
        if (get<1>(t) == 0) {
            rep(k, 4) {
                func(p.first, p.second, kNight[k].first, kNight[k].second, t);
                func(p.first, p.second, -kNight[k].first, -kNight[k].second, t);
            }
        } else {
            rep(k, 2) {
                func(p.first, p.second, miniBishop[k].first,
                     miniBishop[k].second, t);
                func(p.first, p.second, -miniBishop[k].first,
                     -miniBishop[k].second, t);
            }
        }
    }

    int ans = min(get(make_tuple(g, 0)), get(make_tuple(g, 1)));
    if (ans == INF)
        cout << "-1" << endl;
    else
        cout << ans << endl;

    return 0;
}
