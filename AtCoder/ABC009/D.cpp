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

using Vector = vector<uint32_t>;
using Matrix = vector<Vector>;
int K, M;
uint32_t A[102], C[102];

Matrix mul(const Matrix &m1, const Matrix &m2) {
    Matrix ret(m1.size(), Vector(m1.size()));
    rep(i, m1.size()) rep(j, m1.size()) rep(k, m1.size()) {
        // printf("%d ^= %d & %d ((%d,%d) ^ (%d,%d) &
        // (%d,%d))\n",ret[i][j],m1[i][k],m2[k][j],i,j,i,k,k,j);
        ret[i][j] ^= m1[i][k] & m2[k][j];
    }

    return ret;
}

Matrix power(Matrix m, ll n) {
    Matrix t(m.size(), Vector(m[0].size()));
    if (n == 0) {
        rep(i, t.size()) t[i][i] = 0xFFFFFFFF;
    } else {
        if (n % 2 == 1)
            t = mul(m, power(mul(m, m), n >> 1));
        else
            t = power(mul(m, m), n >> 1);
    }
    return t;
}

void print(const Matrix &m) {
    for (auto v : m) {
        for (auto e : v) cout << e << " ";
        cout << endl;
    }
}
int main() {
    cin >> K >> M;
    rep(i, K) cin >> A[i];
    rep(i, K) cin >> C[i];
    Matrix m(K, Vector(K));
    rep(i, K) m[i][i + 1] = 0xFFFFFFFF;
    rep(i, K) m.back()[i] = C[K - i - 1];
    m = power(m, M - 1);
    uint32_t ans = 0;
    rep(i, K) ans ^= m.front()[i] & A[i];

    cout << ans << endl;

    return 0;
}
