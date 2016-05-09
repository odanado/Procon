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
vector<int> C;
int main() {
    cin >> N;
    C.resize(N);
    rep(i, N) cin >> C[i];
    double ans = 0.0;

    rep(i, N) {
        int cnt = 0;
        rep(j, N) if (i != j && C[i] % C[j] == 0) cnt++;
        if (cnt % 2 == 1)
            ans += 0.5;
        else
            ans += (cnt + 2) / (2.0 * cnt + 2);
    }
    printf("%.8f\n", ans);
    return 0;
}
