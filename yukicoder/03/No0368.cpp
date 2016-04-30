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

int N, K;
int a[1003];
map<int, vector<int>> mp;

void factor(int n) {
    ll i = 2;
    while (n != 1) {
        int cnt = 0;
        while (n % i == 0) {
            cnt++;
            n /= i;
        }
        if (cnt) {
            mp[i].push_back(cnt);
        }
        if(i*i>n) {
            mp[n].push_back(1);
            return;
        }
        i++;
    }
}

ll mod_pow(ll a, int n, int m) {
    ll res = 1;
    while (n) {
        if (n & 1) {
            res *= a;
            res %= m;
        }
        n >>= 1;
        a *= a;
        a %= m;
    }
    return res;
}

int main() {
    cin >> N >> K;
    rep(i, N) cin >> a[i];
    rep(i, N) factor(a[i]);

    ll ans = 1;
    for (auto &e : mp) {
        sort(all(e.second));
        reverse(all(e.second));
        int cnt = 0;
        rep(i, min(K, (int)e.second.size())) cnt += e.second[i];
        ans *= mod_pow(e.first, cnt, MOD);
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}
