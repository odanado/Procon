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
vector<int> H, W;
int dp[100005];
int calc(vector<int> H, vector<int> W) {
    vector<pair<int, int>> vec;
    rep(i, N) vec.push_back(make_pair(W[i], -H[i]));
    sort(all(vec));
    vector<int> a;
    rep(i, N) {
        W[i] = vec[i].first;
        H[i] = -vec[i].second;
    }

    rep(i,N) a.push_back(H[i]);
    // cout << a.size() << endl;
    // for (auto x : a) cout << x << ", ";
    // cout << endl;
    rep(i, 100005) dp[i] = INF;

    rep(i, a.size()) { *lower_bound(dp, dp + N, a[i]) = a[i]; }
    // cout << lower_bound(dp, dp + N, INF) - dp << endl;
    return lower_bound(dp, dp + N, INF) - dp;
}
int main() {
    cin >> N;
    H.resize(N);
    W.resize(N);
    rep(i, N) { cin >> W[i] >> H[i]; }

    cout << max(calc(W, H), calc(H, W)) << endl;

    return 0;
}
