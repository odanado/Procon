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

int H, W;
int K;
string s[1003];
int imos[3][1003][1003];
int get(int i, int y, int x) {
    if (y < 0 || x < 0) return 0;
    // cout << i << ", " << y << ", " << x << ": " << imos[i][y][x] << endl;
    return imos[i][y][x];
}
int get(int i, int y1, int x1, int y2, int x2) {
    return get(i, y2, x2) - get(i, y2, x1 - 1) - get(i, y1 - 1, x2) +
           get(i, y1 - 1, x1 - 1);
}
int main() {
    cin >> H >> W >> K;
    rep(i, H) cin >> s[i];
    rep(y, H) rep(x, W) {
        int t = 0;
        if (s[y][x] == 'O') t = 1;
        if (s[y][x] == 'I') t = 2;
        imos[t][y][x]++;
    }
    rep(i, 3) rep(y, 1003) rep(x, 1003) if (x) {
        imos[i][y][x] += imos[i][y][x - 1];
    }
    rep(i, 3) rep(y, 1003) rep(x, 1003) if (y) {
        imos[i][y][x] += imos[i][y - 1][x];
    }

    rep(_, K) {
        int y1, x1;
        int y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        y1--, x1--;
        y2--, x2--;
        rep(i, 3) {
            cout << get(i, y1, x1, y2, x2);
            if(i==2) cout<<endl;
            else cout << " ";
        }
    }

    return 0;
}
