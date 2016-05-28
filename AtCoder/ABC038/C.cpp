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

ll calc(ll n) { return n * (n + 1) / 2; }

int main() {
    int N;
    vector<int> a;
    cin >> N;
    a.resize(N);
    rep(i, N) cin >> a[i];
    int s = 0, t = 1;
    ll ans = 0;
    while (t < N) {
        while (t < N && a[t - 1] < a[t]) t++;
        ans += calc(t - s);
        //printf("%d %d\n", s, t);
        s = t;
        t++;
    }
    if (s != N) ans += calc(t - s);
    cout << ans << endl;

    return 0;
}
