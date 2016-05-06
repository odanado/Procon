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

const ll INF = 1e10;
const ll MOD = 1e9 + 7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

ll n, k;
int a[100005], b[100005];
bool ok(ll x) {
    ll sum = 0;
    rep(i, n) {
        ll t = b[i] - x * a[i];
        if (t < 0) sum += t;
        if (sum + k < 0) return false;
    }
    return true;
}
int main() {
    cin >> n >> k;
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    ll lb = 0, ub = INF;
    while (ub - lb > 1) {
        ll mid = (ub + lb) / 2;
        if (ok(mid))
            lb = mid;
        else
            ub = mid;
    }
    cout << lb << endl;
    return 0;
}
