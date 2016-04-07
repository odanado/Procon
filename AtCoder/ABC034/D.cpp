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

int N, K;
int w[1003], p[1003];
bool ok(double t) {
    vector<double> vec;
    rep(i, N) vec.push_back(w[i] * (p[i]/100.0 - t));
    sort(all(vec));
    reverse(all(vec));

    double sum = 0;
    rep(i, K) sum += vec[i];
    return sum >= 0.0;
}
int main() {
    cin >> N >> K;
    rep(i, N) cin >> w[i] >> p[i];
    double lb = 0, ub = 1;
    rep(i, 100) {
        double mid = (lb + ub) / 2;
        if (ok(mid))
            lb = mid;
        else
            ub = mid;
    }
    printf("%.12f\n", (lb+ub) / 2 * 100);
    return 0;
}
