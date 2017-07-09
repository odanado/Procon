#include <bits/stdc++.h>

using namespace std;

#define all(c) (c).begin(), (c).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int N;
vector<string> S;
void solve() {
    int cnt = 0;
    string ans = "YES";
    rep(i, N) {
        if (S[i] == "A")
            cnt++;
        else
            cnt--;
        if (cnt < 0) {
            ans = "NO";
            break;
        }
    }
    if (cnt != 0) ans = "NO";
    cout << ans << endl;
}
int main() {
    while (cin >> N) {
        S.resize(N);
        rep(i, N) cin >> S[i];
        solve();
    }

    return 0;
}
