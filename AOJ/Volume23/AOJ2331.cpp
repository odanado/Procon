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

int N;
int a[100005];
int b[100005];
int imos[100005];
bool ok(int m) { return imos[m] >= m; }
int main() {
    cin >> N;
    rep(i, N) cin >> a[i] >> b[i];
    rep(i, N) a[i]--, b[i]--;
    rep(i, N) {
        ++imos[a[i]];
        --imos[b[i] + 1];
    }
    rep(i, 100005) if (i) imos[i] += imos[i - 1];
    // rep(i, N + 1) cout << i << ", " << imos[i] << endl;
    int ans = 0;
    rep(i, N + 1) if (ok(i)) ans = i;
    cout << ans << endl;
    return 0;
}
