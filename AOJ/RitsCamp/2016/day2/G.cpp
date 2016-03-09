#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

template<class T>
bool chmax(T &a, const T &b) {
    if(a<b) {
        a=b;
        return true;
    }
    return false;
}

int n,x,y;
int a[102],b[102],c[102],d[102];

// idx, umaka, fugashi
int dp[102][302][700];
const int offset = 301;

#define at(i,j,k) dp[i][j][k+offset]

int dfs(int i,int j,int k) {
    if(i==n) return 0;
    int ret=dfs(i+1,j,k);
    if(j>=a[i]) ret=max(ret,dfs(i+1,j-a[i],k+b[i]));
    ret=max(ret,dfs(i+1,j,k-c[i])+d[i]);
    return ret;
}

int main() {
    cin>>n>>x>>y;
    rep(i,n) {
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    }
    rep(i,102) rep(j,302) rep(k,302*2) dp[i][j][k]=-1e8;
    at(0,x,y)=0;

    rep(i,n) rep(j,302) for(int k=-301;k<=301;k++) {
        //cout<<i<<", "<<j<<", "<<k<<endl;
        chmax(at(i+1,j,k),at(i,j,k));
        if(j-a[i]>=0&&k+b[i]<303*2) chmax(at(i+1,j-a[i],k+b[i]),at(i,j,k));
        if(k-c[i]+offset>=0) chmax(at(i+1,j,k-c[i]), at(i,j,k)+d[i]);
    }
    int ans=-1e8;
    rep(i,n+1) rep(j,302) rep(k,302) chmax(ans,at(i,j,k));
    cout<<ans<<endl;

    return 0;
}
