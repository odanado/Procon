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

int N, M;
int X, Y;
vector<int> a, b;
int main() {
    cin >> N >> M;
    cin >> X >> Y;
    a.resize(N);
    b.resize(M);
    rep(i, N) cin >> a[i];
    rep(i, M) cin >> b[i];
    int ans = 0;
    int t = a.front();
    while (1) {
        // cout<<t<<endl;
        if (ans % 2 == 0) {
            auto it = lower_bound(all(b), t + X);
            if (it == b.end()) break;
            t = *it;
        } else {
            auto it = lower_bound(all(a), t + Y);
            if (it == a.end()) break;
            t = *it;
        }
        ans++;
    }
    cout << (ans + 1) / 2 << endl;
    return 0;
}
