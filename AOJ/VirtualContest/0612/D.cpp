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

int n;
string f[102];
void solve() {
    int left = 0, right = 0;
    // 次に目指す状態 1なら上，2なら下
    int next_status = 1;
    int ans = 0;
    rep(i, n) {
        if (f[i][0] == 'l') {
            if (left == 0 and f[i][1] == 'u') {
                left ^= 1;
            }
            if (left == 1 and f[i][1] == 'd') {
                left ^= 1;
            }
        } else {
            if (right == 0 and f[i][1] == 'u') {
                right ^= 1;
            }
            if (right == 1 and f[i][1] == 'd') {
                right ^= 1;
            }
        }
        if (left == right) {
            if (next_status == left) {
                ans++;
                next_status ^= 1;
            }
        }
    }
    cout << ans << endl;
}
int main() {
    while (cin >> n, n) {
        rep(i, n) cin >> f[i];
        solve();
    }
    return 0;
}
