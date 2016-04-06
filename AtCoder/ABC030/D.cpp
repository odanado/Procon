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

int N, a;
string k;
vector<int> b;
int main() {
    cin >> N >> a;
    a--;
    cin >> k;
    b.resize(N);
    rep(i, N) cin >> b[i];
    rep(i, N) b[i]--;

    int d, cycle;
    vector<int> vs;
    vector<int> dist;
    dist.assign(N, INF);
    int v = a;

    int cnt = 0;
    while (1) {
        vs.push_back(v);
        if (dist[v] != INF) {
            d = dist[v];
            cycle = cnt - d;
            break;
        }
        dist[v] = cnt;
        v = b[v];
        cnt++;
    }
    // cout << d << ", " << cycle << endl;
    if (k.size() < 8) {
        int t;
        stringstream ss;
        ss << k;
        ss >> t;
        if (t < vs.size()) {
            cout << vs[t] + 1 << endl;
        } else {
            cout << vs[d + (t - d) % cycle] + 1 << endl;
        }
    } else {
        int t = 0;
        rep(i, k.size()) t = (t * 10 + k[i] - '0') % cycle;
        t = (t - d) % cycle;
        t = (t + cycle) % cycle;
        cout << vs[t + d] + 1 << endl;
    }

    return 0;
}
