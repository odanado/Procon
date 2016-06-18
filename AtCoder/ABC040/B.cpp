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
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

const ll inf = 1e18;
const ll mod = 1e9 + 7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int n;
    cin >> n;
    ll ans = inf;
    rep(i, n + 1) if (i) {
        int j = n / i;
        // cout << i << ", " << j << endl;
        ll t = abs(i - j) + n - i * j;
        ans = min(t, ans);
    }
    cout << ans << endl;
    return 0;
}
