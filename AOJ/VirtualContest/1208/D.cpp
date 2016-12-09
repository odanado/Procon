#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

string s;
void solve() {
    set<string> cnt;
    cnt.insert(s);
    rep(i, s.size()) {
        if (i == 0) continue;
        auto s1 = s.substr(0, i);
        auto s2 = s.substr(i);
        cnt.insert(s1 + s2);
        cnt.insert(s2 + s1);

        reverse(s1.begin(), s1.end());
        cnt.insert(s1 + s2);
        cnt.insert(s2 + s1);

        reverse(s2.begin(), s2.end());
        cnt.insert(s1 + s2);
        cnt.insert(s2 + s1);

        reverse(s1.begin(), s1.end());
        cnt.insert(s1 + s2);
        cnt.insert(s2 + s1);
    }
    cout << cnt.size() << endl;
}
int main() {
    int m;
    cin >> m;
    rep(i, m) {
        cin >> s;
        solve();
    }
}
