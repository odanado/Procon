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

int M, T, P, R;
int m[2003], t[2003], p[2003], j[2003];
int correct[51], penalty[51][11], times[51][11];
void solve() {
    memset(correct, 0, sizeof(correct));
    memset(penalty, 0, sizeof(penalty));
    memset(times, 0, sizeof(times));
    rep(i, R) {
        if (j[i] == 0) {
            correct[t[i]]++;
            times[t[i]][p[i]] += m[i];
            times[t[i]][p[i]] += penalty[t[i]][p[i]] * 20;
        } else {
            penalty[t[i]][p[i]]++;
        }
    }
    vector<tuple<int, int, int>> vec;
    rep(i, T) {
        int sum = 0;
        rep(k, P + 1) sum += times[i][k];
        vec.emplace_back(-correct[i], sum, -i);
    }
    sort(all(vec));
    tuple<int, int, int> pre{-1, -1, -1};
    rep(i, vec.size()) {
        auto x = vec[i];
        if (get<0>(x) == get<0>(pre) and get<1>(x) == get<1>(pre)) {
            cout << "=";
        } else {
            if (i) cout << ",";
        }
        cout << -get<2>(x) + 1;

        pre = x;
    }
    cout << endl;
}
int main() {
    while (cin >> M >> T >> P >> R, M) {
        rep(i, R) cin >> m[i] >> t[i] >> p[i] >> j[i];
        rep(i, R) t[i]--;
        solve();
    }
    return 0;
}
