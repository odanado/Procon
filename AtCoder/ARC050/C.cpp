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

ll power(ll a, ll n, ll m) {
    ll ret = 1;
    while (n) {
        if (n & 1) ret = (ret * a) % m;
        n >>= 1;
        a *= a;
        a %= m;
    }
    return ret;
}
ll one(ll base, ll n, ll m) {
    if (n == 0) return 0;
    if (n % 2 == 0)
        return one(base, n / 2, m) * (power(base, n / 2, m) + 1) % m;
    else
        return (one(base, n - 1, m) * base + 1) % m;
}
ll A, B, M;
int main() {
    cin >> A >> B >> M;
    ll g = __gcd(A, B);
    ll x = one(10, A, M);
    ll y = one(power(10, g, M), B / g, M);
    ll ans = x * y;
    ans = (ans % M + M) % M;
    cout << ans << endl;
    return 0;
}
