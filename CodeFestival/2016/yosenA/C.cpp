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

string s;
int K;
int dist(char c) {
    if (c == 'a') return 0;
    return 'z' - c + 1;
}
char advance(char c, int t) {
    rep(i, t) {
        if (c == 'z')
            c = 'a';
        else
            c++;
    }
    return c;
}
int main() {
    cin >> s >> K;
    rep(i, s.size()) {
        if (K == 0) break;
        int t = dist(s[i]);
        if (t <= K) {
            s[i] = advance(s[i], t);
            K -= t;
        } else {
        }
    }
    int n = s.size();
    s[n - 1] = advance(s[n - 1], K % 26);
    cout << s << endl;
    return 0;
}
