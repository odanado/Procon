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

string s;
vector<string> ans;
void dfs(int idx, int S) {
    if (idx == s.size()) {
        ans.push_back(s);
        return;
    }
    int t = s[idx] - 'a';
    if (S >> t & 1) {
        dfs(idx + 1, S);
    }
    if (!(S >> (t + 1) & 1)) {
        if (t != 25) {
            s[idx]++;
            dfs(idx + 1, S | 1 << (t + 1));
            s[idx]--;
        }
    }
}

int main() {
    while (cin >> s) {
        if (s == "#") break;
        ans.clear();
        dfs(0, 1);
        sort(all(ans));
        cout << ans.size() << endl;
        if (ans.size() > 10) {
            rep(i, 5) cout << ans[i] << endl;
            rep(i, 5) cout << ans[ans.size() + i - 5] << endl;
        } else
            for (auto e : ans) cout << e << endl;
    }
    return 0;
}
