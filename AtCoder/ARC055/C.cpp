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

struct RollingHash {
    typedef long long int_type;
    typedef pair<int_type, int_type> hash_type;

    int_type base1;
    int_type base2;
    int_type mod1;
    int_type mod2;
    vector<int_type> hash1;
    vector<int_type> hash2;
    vector<int_type> pow1;
    vector<int_type> pow2;

    RollingHash()
        : base1(1009), base2(1007), mod1(1000000007), mod2(1000000009) {}

    void init(const string &s) {
        int n = s.size();

        hash1.assign(n + 1, 0);
        hash2.assign(n + 1, 0);
        pow1.assign(n + 1, 1);
        pow2.assign(n + 1, 1);

        for (int i = 0; i < n; i++) {
            hash1[i + 1] = (hash1[i] + s[i]) * base1 % mod1;
            hash2[i + 1] = (hash2[i] + s[i]) * base2 % mod2;
            pow1[i + 1] = pow1[i] * base1 % mod1;
            pow2[i + 1] = pow2[i] * base2 % mod2;
        }
    }

    hash_type get(int l, int r) {
        int_type t1 =
            ((hash1[r] - hash1[l] * pow1[r - l]) % mod1 + mod1) % mod1;
        int_type t2 =
            ((hash2[r] - hash2[l] * pow2[r - l]) % mod2 + mod2) % mod2;
        return make_pair(t1, t2);
    }

    RollingHash::hash_type concat(hash_type h1, hash_type h2, int h2_len) {
        return make_pair((h1.fr * pow1[h2_len] + h2.fr) % mod1,
                         (h1.sc * pow2[h2_len] + h2.sc) % mod2);
    }
};

int main() {
    string s;
    cin >> s;
    if(s.size() > 2000) return 0;
    RollingHash rh;
    rh.init(s);
    int ans = 0;
    rep(a, s.size()) rep(c, s.size()) if (a && c) {
        int b = s.size();
        b -= a * 2;
        b -= c * 2;
        if (b <= 0) continue;
        if (rh.get(0, a) == rh.get(a + b + c, a + b + c + a) &&
            rh.get(a + b, a + b + c) ==
                rh.get(a + b + c + a, a + b + c + a + c)) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
