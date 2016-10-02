#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

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

int cnt[26];
int N, K;
string P[10004];

int next(int &S) {
    int ret = -1;
    int maxi = 0;
    rep(i, 26) {
        if (S >> i & 1) continue;
        if (cnt[i] && maxi < cnt[i]) {
            maxi = cnt[i];
            ret = i;
        }
    }
    if (ret != -1) S |= 1 << ret;
    return ret;
}

int main() {
    cin >> N >> K;
    rep(i, N) cin >> P[i];
    rep(i, N) cnt[P[i][0] - 'A']++;
    int ans = 0;

    bool isfinish = true;
    while (isfinish) {
        int S = 0;
        rep(i, K) {
            int c = next(S);
            if (c == -1) isfinish = false;
            cnt[c]--;
        }
        ans++;
    }
    cout << ans - 1 << endl;

    return 0;
}
