#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
int N;
vector<int> t[20];
int dp[1<<16];
int dp2[1<<16];

int dfs(int S) {
    if(S == (1<<N)-1) return 0;
    if(dp[S] != -1) return dp[S];
    int ret = 1000000000;

    //i番目をj番目の装備で攻略
    rep(i,N) {
        if((S>>i)&1) continue;
        rep(j,N) {
            if(i==j) continue;
            if(!((S>>j)&1)) continue;

            ret = min(ret, dfs(S|(1<<i)) + t[i][j+1]);
        }
        ret = min(ret, dfs(S|(1<<i)) + t[i][0]);
    }
    return dp[S]=ret;

}

void solve() {
    rep(i,1<<16) dp[i]=-1;
    rep(i,N) {
        t[i].resize(N+1);
        rep(j,N+1) {
            int a;
            cin>>a;
            t[i][j]=a;
        }
    }
    /*
    rep(i,1<<16) dp2[i]=100000000;
    dp2[0]=0;
    rep(i,1<<N) {
        rep(j,N) {
            //状態i でjを攻略
            if(!((i>>j)&1)) {
                rep(k,N) {
                    if((i>>k)&1) dp2[i|(1<<j)] = min(dp2[i|(1<<j)], dp2[i]+t[j][k+1]);
                }
                dp2[i|(1<<j)] = min(dp2[i|(1<<j)], dp2[i] + t[j][0]);
            }
        }
    } 
    cout<<dp2[(1<<N)-1]<<endl;

    */
    int ans = 1000000000;
    ans = dfs(0);
    cout<<ans<<endl;

    rep(i,N) t[i].clear();

}
int main() {

    while(cin>>N) {
        if(!N) return 0;
        solve();
    }

    return 0;
}
