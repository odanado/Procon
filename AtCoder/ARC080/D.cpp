#include <bits/stdc++.h>

using namespace std;

#define all(c) (c).begin(), (c).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int H, W;
int N;
int a[10004];
int main() {
    cin >> H >> W;
    cin >> N;
    rep(i, N) cin >> a[i];
    vector<vector<int>> ans(H);

    int idx = 0;
    rep(i, N) {
        while (a[i]--) {
            // cout << idx << endl;
            ans[idx / W].push_back(i + 1);
            idx++;
        }
    }
    rep(i, H) {
        if (i % 2 == 1) reverse(all(ans[i]));
        rep(j, W) cout << ans[i][j] << " ";
        cout << endl;
    }

    return 0;
}
