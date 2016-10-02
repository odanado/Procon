#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

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

int N;
bool stop = false;
void dfs(string s1, string s2, bool f) {
    if (s1.size() == N) return;
    if (stop) return;
    string res;
    bool f2 = false;
    rep(i, 2) rep(j, 2) {
        if (stop) return;
        char c1 = i == 0 ? '.' : '#';
        char c2 = j == 0 ? '.' : '#';
        string t1, t2;
        if (f) {
            t1 = s1 + c1;
            t2 = s2 + c2;
        } else {
            t1 = c1 + s1;
            t2 = c2 + s2;
        }
        printf("%s\n%s\n", t1.c_str(), t2.c_str());
        fflush(stdout);
        cin >> res;
        if (res == "end") {
            stop = true;
            break;
        }
        if (res == "T") {
            dfs(t1, t2, f);
            f2 = true;
        }
        if (stop) return;
    }
    if (!f2) dfs(s1, s2, !f);
}
int main() {
    cin >> N;
    dfs("", "", 1);
    return 0;
}
