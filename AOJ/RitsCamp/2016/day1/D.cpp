#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int s=0;
int upper;
int N;
int T[51];
int dp[51][900][900];

int dfs(int idx,int a,int b) {
    if(idx==N) {
        int t=max({a,b,s-a-b});
        return t;
    }
    if(dp[idx][a][b]!=-1) return dp[idx][a][b];
    int ret=dfs(idx+1,a,b);
    if(upper>a+T[idx]) ret=min(ret,dfs(idx+1,a+T[idx],b));
    if(upper>b+T[idx]) ret=min(ret,dfs(idx+1,a,b+T[idx]));
    return dp[idx][a][b]=ret;
}

int main() {
    memset(dp,-1,sizeof(dp));
    cin>>N;
    rep(i,N) cin>>T[i];
    rep(i,N) s+=T[i];
    upper=s/3+51;
    cout<<dfs(0,0,0)<<endl;
    return 0;
}

