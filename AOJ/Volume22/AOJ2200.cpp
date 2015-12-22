#include<stdio.h>
#include<iostream>
#include<queue>
#include<algorithm>
#include<functional>
#include<map>
#include<string>
#include<vector>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
const int INF=10000000;

int n,m;
int ldist[203][203];
int sdist[203][203];
int z[1003];
int dp[1003][203];

void solve() {
    rep(i,203) rep(j,203) ldist[i][j]=sdist[i][j]=INF;
    rep(i,203) ldist[i][i]=sdist[i][i]=0;
    rep(i,m) {
        int s,t,cost;
        char c;
        cin>>s>>t>>cost>>c;
        if(c=='L') ldist[s][t]=ldist[t][s]=min(ldist[s][t],cost);
        if(c=='S') sdist[s][t]=sdist[t][s]=min(sdist[s][t],cost);
    }
    rep(k,n+1) rep(i,n+1) rep(j,n+1) { 
        ldist[i][j]=min(ldist[i][j],ldist[i][k]+ldist[k][j]);
        sdist[i][j]=min(sdist[i][j],sdist[i][k]+sdist[k][j]);
    }

    int R;
    cin>>R;
    rep(i,R) cin>>z[i];
    //集配順,船の位置のDP

    rep(i,1003) rep(j,203) dp[i][j]=INF;
    dp[0][z[0]]=0;

    for(int i=1;i<R;i++) rep(j,n+1) {
        dp[i][j]=min(dp[i][j],dp[i-1][j]+ldist[z[i-1]][z[i]]);
        rep(k,n+1) {
            dp[i][k]=min(dp[i][k],dp[i-1][j]+ldist[z[i-1]][j]+
                    sdist[j][k]+ldist[k][z[i]]);
        }
    }
    int ans=INF;
    rep(i,n+1) ans=min(ans,dp[R-1][i]);
    cout<<ans<<endl;


    
}
int main() {
    while(cin>>n>>m) {
        if(n+m==0) return 0;
        solve();
    }

    return 0;
}

/* 2014/05/12 AC  */
