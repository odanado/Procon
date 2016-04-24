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
#include <stack>
#include <cassert>

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
using P = pair<int, int>;

int calcScore(stack<P> st, int player) {
    int res = 0;
    while (st.size()) {
        auto p = st.top();
        if (p.second != player && p.first == -1) break;
        if (p.second == player && p.first != -1) res += p.first;
        st.pop();
    }
    return res;
}

int calcScore(stack<P> st) { return calcScore(st, 0) - calcScore(st, 1); }

int n, m;
int a[51], b[51];

map<tuple<int, int, stack<P>, int, int>, int> dp;

int dfs(int idx1, int idx2, stack<P> st, int player, int pass) {
    if (pass == 3) {
        return 0;
    }
    auto key = tie(idx1, idx2, st, player, pass);
    if (dp.count(key)) return dp[key];

    int res;
    if (player == 0) {
        res = -INF;
        if (idx1 < n) {
            st.push(P(a[idx1], player));
            res = max(res, dfs(idx1 + 1, idx2, st, player ^ 1, 0));
            st.pop();
        }
        if (pass < 3) {
            int t = calcScore(st);
            st = stack<P>();
            res = max(res, dfs(idx1, idx2, st, player ^ 1, pass + 1) + t);
        }
    } else {
        res = INF;
        if (idx2 < m) {
            st.push(P(b[idx2], player));
            res = min(res, dfs(idx1, idx2 + 1, st, player ^ 1, 0));
            st.pop();
        }
        if (pass < 3) {
            int t = calcScore(st);
            st = stack<P>();
            res = min(res, dfs(idx1, idx2, st, player ^ 1, pass + 1) + t);
        }
    }

    return dp[key] = res;
}

int main() {
    cin >> n >> m;
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    cout << dfs(0, 0, stack<P>(), 0, 0) << endl;
    return 0;
}
