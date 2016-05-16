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

bool contains(ll n) {
    bool f = false;
    while (n) {
        ll t = n % 10;
        if (t == 4 || t == 9) f = true;
        n /= 10;
    }
    return f;
}

ll f(ll n) {
    ll cnt = 0;
    rep(i, n + 1) if (i) {
        if (contains(i)) cnt++;
    }
    return cnt;
}
ll dp[20][2][2];
// idx,すでに数字が禁止されているか
ll dfs(string S, int idx, bool ng, bool f) {
    if (idx == S.size()) {
        return ng;
    }
    if (dp[idx][ng][f] != -1) return dp[idx][ng][f];
    ll res = 0;
    int t = S[idx] - '0';
    rep(i, 10) {
        if (!f) {
            if (i <= t) {
                if (i == 4 || i == 9)
                    res += dfs(S, idx + 1, true, f || i < t);
                else
                    res += dfs(S, idx + 1, ng, f || i < t);
            }
        } else {
            res += dfs(S, idx + 1, ng || i == 4 || i == 9, f);
        }
    }
    return dp[idx][ng][f] = res;
}

string to_s(ll n) {
    stringstream ss;
    ss << n;
    return ss.str();
}

int main() {
    ll A, B;
    cin >> A >> B;
    A--;
    memset(dp, -1, sizeof(dp));
    ll t = dfs(to_s(B), 0, 0, 0);
    memset(dp, -1, sizeof(dp));
    t -= dfs(to_s(A), 0, 0, 0);
    cout << t << endl;
    return 0;
}
