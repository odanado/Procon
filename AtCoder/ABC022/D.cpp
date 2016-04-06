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

pair<double, double> calcGravity(vector<pair<double, double>> &vec) {
    pair<double, double> ret;
    for (auto e : vec) {
        ret.first += e.first;
        ret.second += e.second;
    }
    ret.first /= vec.size();
    ret.second /= vec.size();
    return ret;
}

double calcDist(pair<double, double> p1, pair<double, double> p2) {
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

double calcNearestDist(vector<pair<double, double>> &vec,
                       pair<double, double> p) {
    double ret = calcDist(vec.front(), p);
    for (auto e : vec) {
        ret = max(ret, calcDist(e, p));
    }
    return ret;
}

int N;
vector<pair<double, double>> A, B;
int main() {
    cin >> N;
    A.resize(N);
    B.resize(N);
    rep(i, N) cin >> A[i].first >> A[i].second;
    rep(i, N) cin >> B[i].first >> B[i].second;
    auto g1 = calcGravity(A);
    auto g2 = calcGravity(B);

    auto ans = calcNearestDist(B, g2) / calcNearestDist(A, g1);

    printf("%.12f\n", ans);

    return 0;
}
