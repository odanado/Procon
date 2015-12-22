#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
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
using namespace std;
typedef pair<int ,int > P;
typedef long long ll;

P p1[102],p2[102];
int n;

bool ok(int x,int y,int dx,int dy) {
    int ny=y+dy;
    int nx=x+dx;
    rep(i,n) {
        if(p1[i].fr==x&&p1[i].sc==y && p2[i].fr==nx&&p2[i].sc==ny) return false;
        if(p2[i].fr==x&&p2[i].sc==y && p1[i].fr==nx&&p1[i].sc==ny) return false;
    }

    return true;
}
void solve() {
    int gx,gy;
    cin>>gx>>gy;
    cin>>n;
    rep(i,n) {
        cin>>p1[i].fr>>p1[i].sc;
        cin>>p2[i].fr>>p2[i].sc;
    }
    int dp[20][20];
    rep(i,20) rep(j,20) dp[i][j]=0;
    dp[0][0]=1;
    rep(x,19) rep(y,19) {
        if(ok(x,y,1,0)) dp[x+1][y]+=dp[x][y];
        //else dp[x+1][y]=0;
        if(ok(x,y,0,1)) dp[x][y+1]+=dp[x][y];
        //else dp[x][y+1]=0;
    }
    int ans=dp[gx][gy];
    if(ans) cout<<ans<<endl;
    else cout<<"Miserable Hokusai!"<<endl;

}
int main() {
    int t;
    cin>>t;
    while(t-->0) {
        solve();
    }

    return 0;
}

