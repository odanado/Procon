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

void f(int *a,int *b,int n) {
    rep(i,n) a[i]-=b[i];
}

int n, k;
int a[1003], b[1003];
int main() {
    cin >> n >> k;
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    int ans = 0;
    while(1) {
        f(b, a, n);
        rep(i,n) {
            if(b[i]<0) {
                k+=b[i];
                b[i]=0;
            }
        }
        if(k<0) break;

        ans++;
    }
    cout << ans << endl;



    return 0;
}
