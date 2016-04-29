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

int N, K;
vector<int> a;
int main() {
    cin >> N >> K;
    a.resize(N);
    rep(i, N) cin >> a[i];
    if (is_sorted(all(a))) {
        cout << "0" << endl;
        return 0;
    }
    int ans = 0;
    rep(k, K) {
        for (int i = k; i < N - K + k; i += K) {
            for (int j = N - K + k; j > i; j -= K) {
                //printf("debug: %d %d %d\n", k, i, j);
                if(j-K<0) continue;
                //printf("debug: %d %d\n",j-K,j);
                if (a[j - K] > a[j]) {
                    swap(a[j - K], a[j]);
                    ans++;
                }
            }
        }
    }
    if(!is_sorted(all(a))) cout<<"-1"<<endl;
    else cout<<ans<<endl;
    return 0;
}
