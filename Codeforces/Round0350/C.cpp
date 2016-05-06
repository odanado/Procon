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
int a[200005];
int m;
int b[200005];
int c[200005];
int t1, t2;
map<int,int> mp;
int main() {
    cin >> n;
    rep(i, n) cin >> a[i];
    rep(i, n) mp[a[i]]++;
    cin >> m;
    rep(i, m) cin >> b[i];
    rep(i, m) cin >> c[i];

    t1 = t2 = -1;
    int ans = -1;
    rep(i, m) {
        int bc = mp[b[i]];
        int cc = mp[c[i]];
        if (t1 < bc) {
            ans = i;
            t1 = bc;
            t2 = cc;
        } else if (t1 == bc && t2 < cc) {
            ans = i;
            t1 = bc;
            t2 = cc;
        }
    }

    cout << ans + 1 << endl;

    return 0;
}
