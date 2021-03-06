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

int n, k;
int a[100005];
ll sum, ans;
int main() {
    cin >> n >> k;
    rep(i, n) cin >> a[i];
    rep(i, k) sum += a[i];
    for (int i = 0; i < n - k; i++) {
        ans += sum;
        sum -= a[i];
        sum += a[i + k];
    }
    ans += sum;
    cout << ans << endl;
    return 0;
}
