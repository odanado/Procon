#include <algorithm>
#include <iostream>
#include <set>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
int h[5];
void solve() {
    set<int> s;
    rep(i, 5) s.insert(h[i]);
    if (s.size() == 3 || s.size() == 1) {
        rep(i, 5) cout << "3" << endl;
    } else {
        int a1 = *max_element(h, h + 5);
        int a2 = *min_element(h, h + 5);
        int b1, b2;
        if ((a1 + 1) % 3 == a2) {
            b1 = 1;
            b2 = 2;
        } else {
            b1 = 2;
            b2 = 1;
        }
        rep(i, 5) {
            if (h[i] == a1)
                cout << b1 << endl;
            else
                cout << b2 << endl;
        }
    }
}
int main() {
    while (cin >> h[0], h[0]) {
        rep(i, 4) cin >> h[i + 1];
        solve();
    }
}
