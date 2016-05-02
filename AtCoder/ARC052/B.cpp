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

const double PI = acos(-1.0);

double cone(double r, double h) { return PI * r * r * h / 3.0; }

double S(int X, int R, int H, int A, int B) {
    if (B < X || X + H <= A) return 0;
    if (A <= X && X + H < B) {
        return cone(R, H);
    }
    if (X <= A && B <= X + H) {
        double h1 = X + H - B;
        double r1 = 1.0 * R * h1 / H;
        double h2 = X + H - A;
        double r2 = 1.0 * R * h2 / H;
        return PI * (B - A) * (r1 * r1 + r1 * r2 + r2 * r2) / 3.0;
    }
    if (X <= B && B <= X + H) {
        double h = X + H - B;
        double r = 1.0 * R * h / H;
        return cone(R, H) - cone(r, h);
    }
    if (X <= A && A <= X + H) {
        double h = X + H - A;
        double r = 1.0 * R * h / H;
        return cone(r, h);
        // return cone(R, H) - cone(r, h);
    }
    return 0;
}
int N;
int Q;
int X[102], R[102], H[102];
int main() {
    cin >> N >> Q;
    rep(i, N) cin >> X[i] >> R[i] >> H[i];
    while (Q--) {
        int A, B;
        cin >> A >> B;
        double ans = 0.0;
        rep(i, N) ans += S(X[i], R[i], H[i], A, B);
        printf("%.8f\n", ans);
    }
    return 0;
}
