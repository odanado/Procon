#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <climits>

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

const int INF=100000000;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
using namespace std;
typedef pair<int ,int > P;

int n,w;
int v[102];
void solve() {
    int h = 0;
    int maxi = 0;
    int t[202] = {};

    rep(i,n) cin>>v[i];
    rep(i,n) t[v[i]/w]++;
    rep(i,202) h=max(h,t[i]);
    rep(i,202) if(t[i]) maxi=max(maxi,i);

    double ans = 0.01;
    rep(i,maxi+1) ans += 1.0*t[i]/h * 1.0*(maxi-i)/maxi;
    printf("%.10lf\n",ans);
}
int main() {
    while(cin>>n>>w) {
        if(n+w==0) return 0;
        solve();
    }
    return 0;
}

