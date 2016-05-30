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

double s(double x, double y) { return x * sqrt(y * y - (x / 2) * (x / 2)) / 2; }
double a, l, x;
int main() {
    while (cin >> a >> l >> x) {
        double ans = s(a, l);
        ans += s(l, (l + x) / 2);
        ans += s(l, (l + x) / 2);
        printf("%.12f\n", ans);
    }
    return 0;
}
