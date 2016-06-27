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

int N, A, B, C;
int D[102];
int main() {
    cin >> N >> A >> B >> C;
    rep(i, N) cin >> D[i];
    sort(D, D + N);
    reverse(D, D + N);

    int ans = 0;
    int cost = A;
    int cal = C;

    ans = int(1.0 * cal / cost);
    rep(i, N) {
        cal += D[i];
        cost += B;
        // cout <<cal <<", " << cost << endl;
        ans = max(ans, int(1.0 * cal / cost));
    }

    cout << ans << endl;
    return 0;
}
