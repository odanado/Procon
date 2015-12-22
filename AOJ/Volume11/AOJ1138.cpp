#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
int n,m,p,a,b;
const int MAX_N = 8;
const int MAX_M = 30;
const double INF = 1e10;
int t[MAX_N];
int d[MAX_M][MAX_M];
double dp[1<<MAX_N][MAX_M];
void solve() {
    rep(i,1<<n) fill(dp[i],dp[i]+m,INF);
    rep(i,MAX_M) rep(j,MAX_M) d[i][j] = -1;
    rep(i,n) cin>>t[i];
    rep(i,p) {
        int x,y,z;
        cin>>x>>y>>z;
        x--;
        y--;
        d[x][y] = d[y][x] = z;
    }

    dp[(1<<n)-1][a-1] = 0.0;
    double ret = INF;

    for(int S = (1<<n)-1; S>=0;S--) {
        ret = min(ret,dp[S][b-1]);
        rep(v,m) rep(i,n) {
            if(S>>i&1) {
                rep(u,m) {
                    if(d[v][u] == -1) continue;
                    dp[S&~(1<<i)][u] = min(dp[S&~(1<<i)][u],dp[S][v]+(double)d[v][u]/t[i]);
                }
            }
        }
    }
    if(ret == INF) {
        cout<<"Impossible"<<endl;
    }
    else {
        cout<<ret<<endl;
    }

}

int main() {
    while(cin>>n>>m>>p>>a>>b) {
        if(n+m+p+a+b==0) return 0;
        solve();
    }

    return 0;
}

