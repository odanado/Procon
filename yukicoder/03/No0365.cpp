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
vector<int> a;
int main() {
    cin >> N;
    a.resize(N);
    rep(i, N) cin >> a[i];
    int pos = max_element(all(a)) - a.begin();
    int ans = N - pos - 1;
    int v = a[pos];
    for (int i = pos - 1; i >= 0; i--) {
        if (v - 1 != a[i]) {
            ans++;
        } else {
            v = a[i];
        }
    }
    cout << ans << endl;
    return 0;
}
