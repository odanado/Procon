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
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
using namespace std;
typedef pair<int ,int > P;
typedef long long ll;

int n;
int p[50],t[50];


void solve() {
    int dp[50][5];
    rep(i,50) rep(k,5) dp[i][k]=INF;

    if(t[0]<p[0]) {
        printf("NG 1\n");
        return;
    }

    dp[0][1]=p[0];
    rep(i,n-1)  rep(k,4)  {
        if(dp[i][k]==INF) continue;
        int time=t[i+1]-t[i];
        if(p[i+1]+p[i]*(k+1)<=time) dp[i+1][1]=min(dp[i+1][1],dp[i][k]+p[i]+p[i+1]);
        if(k<3&&(abs(p[i+1]-p[i])*(k+1)<=time)) dp[i+1][k+1]=min(dp[i+1][k+1],dp[i][k]+abs(p[i+1]-p[i]));
    }
    /*
    rep(i,n+1) {
        rep(k,5) cout<<dp[i][k]<<" ";
        cout<<endl;
    }
    */
    int ans=INF;
    rep(k,4) ans=min(ans,dp[n-1][k]);
    if(INF>ans) {
        printf("OK %d\n",ans+p[n-1]);
    }
    else {
        int idx=0;
        rep(i,n) {
            bool f=true;
            rep(k,4) f&=dp[i][k]==INF;
            if(f) {
                idx=i;
                break;
            }
        }
        printf("NG %d\n",idx+1);
    }

}

int main() {
    while(cin>>n) {
        if(!n) break;
        rep(i,n) cin>>p[i]>>t[i];
        solve();
    }
    return 0;
}

