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

ll n, k;
ll id[100005];
int main() {
    cin >> n >> k;
    rep(i, n) cin >> id[i];

    ll idx = 0;

    while (idx * (idx + 1) < 2 * k) idx++;

    k -= (idx - 1) * idx / 2;
    k--;

    cout << id[k] << endl;

    return 0;
}
