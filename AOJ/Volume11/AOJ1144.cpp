#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int w,h;
int board[30][30];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int ans = 1000000;

void dfs(int y_,int x_,int cnt) {
    if(cnt == 10) return;
    //cout<<y_<<","<<x_<<","<<cnt<<endl;
    rep(i,4) {
        int x = x_ + dx[i];
        int y = y_ + dy[i];
        if(!((0<=y&&y<h) && (0<=x&&x<w))) continue;
        if(board[y][x] == 1) continue;
        
        while(1) {
            //cout<<y<<","<<x<<endl;
            if(!((0<=y&&y<h) && (0<=x&&x<w))) {
                break;
            }

            if(board[y][x] == 3) {
                ans = min(ans,cnt+1);
                return;
            }
            if(board[y][x] == 1) {
                board[y][x] = 0;
                dfs(y-dy[i],x-dx[i],cnt+1);
                board[y][x] = 1;
                break;
            }
            y+=dy[i];
            x+=dx[i];
        }
        
    }
}
void solve() {
    rep(i,30) rep(j,30) board[30][30] = 0;
    ans = 100000000;
    int sx,sy;
    rep(i,h) rep(j,w) {
        cin>>board[i][j];
        if(board[i][j] == 2) {
            sy = i;
            sx = j;
        }
    }

    dfs(sy,sx,0);
    if(ans == 100000000) ans = -1;
    cout<<ans<<endl;


}
int main() {
    while(cin>>w>>h) {
        if(w+h==0) return 0;
        solve();
    }

    return 0;
}
