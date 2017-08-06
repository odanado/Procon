#include <bits/stdc++.h>

using namespace std;

#define all(c) (c).begin(), (c).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int N;
int a[100005];
int main() {
    cin >> N;
    rep(i, N) cin >> a[i];

    int cnt[3] = {};
    rep(i, N) {
        if (a[i] % 4 == 0)
            cnt[0]++;
        else if (a[i] % 2 == 0)
            cnt[1]++;
        else
            cnt[2]++;
    }
    if (cnt[0] >= cnt[2]) {
        cout << "Yes" << endl;
        return 0;
    }
    if (cnt[1] == 0) {
        if (cnt[0] + 1 >= cnt[2]) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}
