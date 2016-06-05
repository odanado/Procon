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

int M, N;
char joi[1003][1003];
char c[2][2];
bool ok(int y, int x) {
    if (y + 1 >= M || x + 1 >= N) return 0;
    if (y < 0 || x < 0) return 0;
    int ys[] = {0, 0, 1, 1};
    int xs[] = {0, 1, 0, 1};
    rep(i, 4) {
        if (c[ys[i]][xs[i]] != joi[y + ys[i]][x + xs[i]]) {
            return 0;
        }
    }
    return 1;
}
void show() {
    rep(y, M) {
        rep(x, N) cout << joi[y][x] << " ";
        cout << endl;
    }
    cout << endl;
}
bool valid(int y, int x) {
    if (y < 0 || x < 0) return 0;
    if (y >= M || x >= N) return 0;
    return 1;
}
bool f[1003][1003];
int main() {
    cin >> M >> N;
    rep(i, M) rep(j, N) { cin >> joi[i][j]; }
    rep(i, 2) rep(j, 2) cin >> c[i][j];
    int ans = 0;
    rep(y, M) rep(x, N) {
        if (ok(y, x)) ans++;
        f[y][x] = ok(y, x);
        // printf("%d %d %d\n",y,x,ok(y,x));
    }

    string logo = "JOI";
    int maxi = 0;
    rep(y, M) rep(x, N) {
        char tmp = joi[y][x];
        rep(k, logo.size()) {
            int cnt = 0;
            joi[y][x] = logo[k];
            // show();
            for (int dy = -1; dy <= 1; dy++)
                for (int dx = -1; dx <= 1; dx++) {
                    if (!valid(y + dy, x + dx)) continue;
                    if (ok(y + dy, x + dx)) {
                        if (!f[y + dy][x + dx]) cnt++;
                    } else {
                        if (f[y + dy][x + dx]) cnt--;
                    }
                }
            //printf("%d %d %c: %d\n", y, x, logo[k], cnt);
            maxi = max(maxi, cnt);
            joi[y][x] = tmp;
        }
    }

    cout << ans + maxi << endl;
}
