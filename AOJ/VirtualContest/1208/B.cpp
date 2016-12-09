#include <algorithm>
#include <iostream>
#include <set>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int L;
int N[12], M[12];
void solve() {
    int sum = 0;
    int ans = -1;
    rep(i, 12) {
        sum += M[i] - N[i];
        if (L <= sum) {
            ans = i;
            break;
        }
    }
    if (ans == -1)
        cout << "NA" << endl;
    else
        cout << ans + 1 << endl;
}
int main() {
    while (cin >> L, L) {
        rep(i, 12) cin >> M[i] >> N[i];
        solve();
    }
}
