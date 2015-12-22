#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

const int MOD = 1000000;
int dp[102][3][102];
int n,m;
// 場所,どの高さまで真ん中を使ったか
int dfs(int y,int x,int h) {
    int ret = 0;
    if(y<0 || x<0) return 0;
    if(y>n || x>m) return 0;
    cout<<y<<","<<x<<","<<h<<endl;
    if(y==n && x==m) return 1;
    //if(y==n || x==m) return 0;
    if(h!=-1&&dp[y][x][h]!=-1) return dp[y][x][h];

    if(x == 0) {
        if(h<y) {
            ret += dfs(y,x+1,y);
        }
        ret += dfs(y+1,x,h);
    }
    else if(x == 1) {
        ret += dfs(y+1,x,y+1);
        ret += dfs(y,x-1,max(h,y));
        ret += dfs(y,x+1,max(h,y));
        if(h<y) {
            ret += dfs(y-1,x,h);
        }
    }
    else if(x == 2) {
        if(h<y) {
            ret += dfs(y,x-1,y);
        }
        ret += dfs(y+1,x,h);
    }
    return dp[y][x][h]=ret;

}
int main() {
    rep(i,102) rep(j,3) rep(k,102) dp[i][j][k]=-1;
    cin>>n>>m;
    cout<<dfs(0,0,-1)<<endl;


    return 0;
}
