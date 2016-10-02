#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

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

int f(int t) {
    int maxi = 0;
    int ret = 0;
    rep(i, 128) {
        int s = i + (t ^ i);
        if (maxi < s) {
            ret = i;
            maxi = s;
        }
    }
    return ret;
}
int N, D;
void solve() {
    cin >> N >> D;
    int A[128] = {};
    rep(i, 128) A[i] = INF;
    A[D] = 1;
    int sum = 0;
    rep(i, N - 1) {
        int idx = min_element(A, A + 128) - A;

        // cout << idx << endl;
        A[idx]--;
        if (A[idx] == 0) A[idx] = INF;
        int t = f(idx);
        if (A[t] == INF)
            A[t] = 1;
        else
            A[t]++;
        if (A[t ^ idx] == INF)
            A[t ^ idx] = 1;
        else
            A[t ^ idx]++;
    }
    rep(i, 128) {
        if (A[i] != INF) sum += i * A[i];
    }
    cout << sum << endl;
}

int main() {
    int T;
    cin >> T;
    rep(i, T) solve();
    return 0;
}
