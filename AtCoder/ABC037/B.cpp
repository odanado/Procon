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

int N, Q;
int a[102];
int main() {
    cin >> N >> Q;
    rep(i, Q) {
        int l, r, t;
        cin >> l >> r >> t;
        for (int j = l; j <= r; j++) a[j] = t;
    }
    rep(i, N + 1) if (i) cout << a[i] << endl;
    return 0;
}
