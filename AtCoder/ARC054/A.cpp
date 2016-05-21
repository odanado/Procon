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

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

ll L, X, Y, S, D;
int main() {
    cin >> L >> X >> Y >> S >> D;
    double ans = INF;
    ll diff = D - S;
    if (diff == 0) {
        ans = 0.0;
    }
    if (diff > 0) {
        ans = min(ans, 1.0 * diff / (X + Y));
        diff = L - diff;
        if (Y - X > 0) ans = min(ans, 1.0 * diff / abs(Y - X));
    } else {
        if (Y - X > 0) ans = min(ans, 1.0 * abs(diff) / abs(Y - X));
        diff += L;
        ans = min(ans, 1.0 * diff / (X + Y));
    }
    printf("%.8f\n", ans);
    return 0;
}
