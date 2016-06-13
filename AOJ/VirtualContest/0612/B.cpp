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

int n;
int k[102];
string s;
char prev(char c, int m) {
    rep(i, m) {
        if (c == 'a')
            c = 'Z';
        else if (c == 'A')
            c = 'z';
        else
            c--;
    }
    return c;
}
void solve() {
    int idx = 0;
    string ans;
    rep(i, s.size()) {
        char c = prev(s[i], k[idx]);
        ans += c;
        idx++;
        idx %= n;
    }
    cout << ans << endl;
}
int main() {
    while (cin >> n, n) {
        rep(i, n) cin >> k[i];
        cin >> s;
        solve();
    }
    return 0;
}
