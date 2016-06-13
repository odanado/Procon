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

int w, h;
char a[51][51];
bool visited[51][51];
bool ok(int y, int x, char c) {
    bool res = true;
    if (a[y][x] != '.') {
        // if(c=='B') cout << "\t" << y << ", " << x << ": " << a[y][x] << ", "
        // << (a[y][x] == c) << endl;
        return a[y][x] == c;
    }
    rep(k, 4) {
        int ny = y + dy[k];
        int nx = x + dx[k];
        if (ny < 0 || nx < 0) continue;
        if (ny >= h || nx >= w) continue;
        if (visited[ny][nx]) continue;
        visited[ny][nx] = 1;
        res &= ok(ny, nx, c);
    }
    return res;
}
int main() {
    while (cin >> w >> h, w) {
        int W = 0, B = 0;
        bool f = 0;
        rep(i, h) rep(j, w) cin >> a[i][j];
        rep(i, h) rep(j, w) f |= a[i][j] != '.';
        rep(i, h) rep(j, w) {
            memset(visited, 0, sizeof(visited));
            if (a[i][j] != '.') continue;
            if (ok(i, j, 'W')) W++;
            memset(visited, 0, sizeof(visited));
            if (ok(i, j, 'B')) {
                B++;
            }
        }
        if (f)
            cout << B << " " << W << endl;
        else
            cout << "0 0" << endl;
    }
    return 0;
}
