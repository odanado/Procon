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

using Vector = vector<int>;
using Matrix = vector<Vector>;
bool valid(int a, int mini, int maxi) { return mini <= a && a < maxi; }
int W, H;
int N;
int X[31], Y[31];
ll ope(int x, int y, int k, Matrix &grid) {
    // printf("ope: %d %d %d\n", y, x, k);
    ll sum = 0;
    while (valid(x + dx[k], 0, W) && valid(y + dy[k], 0, H)) {
        y += dy[k];
        x += dx[k];
        // printf("debug %d: %d %d %d\n", k, y, x, grid[y][x]);
        if (grid[y][x] == 0) break;
        grid[y][x] = 0;
        sum++;
    }
    return sum;
}
ll run(vector<int> &ord, Matrix &grid) {
    ll sum = 0;
    for (auto i : ord) {
        sum += ope(X[i], Y[i], 0, grid);
        sum += ope(X[i], Y[i], 1, grid);
        sum += ope(X[i], Y[i], 2, grid);
        sum += ope(X[i], Y[i], 3, grid);
        sum++;
        grid[Y[i]][X[i]] = 0;
    }
    return sum;
}
int main() {
    cin >> W >> H;
    cin >> N;
    rep(i, N) cin >> X[i] >> Y[i];
    rep(i, N) X[i]--, Y[i]--;
    if (N > 8 || W > 80 || H > 80) return 0;
    vector<int> ord;
    rep(i, N) ord.push_back(i);

    ll ans = 0;
    do {
        Matrix grid(H, Vector(W, 1));
        ans = max(ans, run(ord, grid));
    } while (next_permutation(all(ord)));

    cout << ans << endl;

    return 0;
}
