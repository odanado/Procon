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

int get(int n) {
    int res = n / 7 * 2;
    res += (n + 1) % 7 == 0;
    return res;
}
int a[1000006];
int b[1000006];

int main() {
    rep(i, 1000006) if (i) {
        a[i] = a[i - 1];
        b[i] = b[i - 1];
        if ((i + 1) % 7 == 0) a[i]++;
        if (i % 7 == 0) a[i]++;
        if ((i + 6) % 7 == 0) b[i]++;
        if ((i + 5) % 7 == 0) b[i]++;
    }
    int n;
    cin >> n;

    cout << a[n] << " " << b[n] << endl;
    return 0;
}
