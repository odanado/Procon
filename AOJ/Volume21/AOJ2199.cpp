#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
int N,M;
int C[20];
int X[20004];
const long long INF = 1000000000000;
long long dp[20004][260];
long long dfs(int i_,int y_) {
    if(i_ == N) return dp[i_][y_] = 0;
    if(dp[i_][y_]!=INF) return dp[i_][y_];

    long long ret = INF;

    rep(i,M) {
        int y = y_ + C[i];
        y = max(y,0);
        y = min(y,255);
        //cout<<y<<","<<X[i_]<<endl;
        ret = min(ret,dfs(i_+1,y)+(X[i_]-y)*(X[i_]-y));

    }
    //cout<<i_<<","<<y_<<","<<ret<<endl;
    return dp[i_][y_] = ret;

}
void solve() {
    rep(i,M) cin>>C[i];
    rep(i,N) cin>>X[i];
    /*
    ans = min(ans,dfs(0,128));
    */

    long long ans = INF;
    rep(i,20004) rep(j,260) dp[i][j] = INF;
    dp[0][128] = 0;
    rep(i,N) {
        rep(j,260) {
            rep(k,M) {
                int y = j + C[k];
                y = max(y,0);
                y = min(y,255);
                dp[i+1][y] = min(dp[i+1][y],dp[i][j]+(X[i]-y)*(X[i]-y));
            }
        }
    }
    rep(i,260) ans=min(ans,dp[N][i]);
    cout<<ans<<endl;

    rep(i,M) C[i] = 0;
    rep(i,N) X[i] = 0;

}
int main() {
    while(cin>>N>>M) {
        if(N+M==0) return 0;
        solve();
    }

    return 0;
}
