#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
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

double n, m;
int main() {
    cin >> n >> m;
    if(n>12) n-=12;
    n = n * 30 + 30 * m / 60;
    m = m * 6;
    double t1 = n - m;
    double t2 = m - n;
    if(t1<0.0) t1+=360;
    if(t2<0.0) t2+=360;
    printf("%.12f\n",min(t1,t2));
    return 0;
}
