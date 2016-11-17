#include <algorithm>
#include <iostream>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int n;
int t[10004];
long long wait_time[10004];
void solve() {
    rep(i, n) wait_time[i] = 0;
    sort(t, t + n);
    rep(i, n) if (i) wait_time[i] += t[i - 1] + wait_time[i - 1];
    long long ans = 0;
    rep(i, n) ans += wait_time[i];
    cout << ans << endl;
}
int main() {
    while (cin >> n) {
        if (n == 0) break;
        rep(i, n) cin >> t[i];
        solve();
    }
}
