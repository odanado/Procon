#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++) 
typedef pair<int,int> P;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int h,w,c;
int tile[10][10];
int cnt_tile() {
    bool visit[10][10] = {};
    int t = tile[0][0];
    int ret = 1;
    queue<P> que;

    que.push(P(0,0));
    visit[0][0] = true;

    while(que.size()) {
        P p = que.front(); que.pop();
        rep(i,4) {
            int y = p.first + dy[i];
            int x = p.second + dx[i];
            if(!(0<=x&&x<w && 0<=y&&y<h)) continue;
            if(visit[y][x]) continue;
            if(tile[y][x] != t) continue;
            visit[y][x] = true;
            if(tile[y][x] == c) ret++;
            que.push(P(y,x));
            
        }
    }
    return ret;
    
}
void fill_tile(int color) {
    bool visit[10][10] = {};
    int t = tile[0][0];
    tile[0][0] = color;
    queue<P> que;

    que.push(P(0,0));
    visit[0][0] = true;

    while(que.size()) {
        P p = que.front(); que.pop();
        rep(i,4) {
            int y = p.first + dy[i];
            int x = p.second + dx[i];
            if(!(0<=x&&x<w && 0<=y&&y<h)) continue;
            if(visit[y][x]) continue;
            if(tile[y][x] != t) continue;
            visit[y][x] = true;
            tile[y][x] = color;
            que.push(P(y,x));
        }
    }

}
int dfs(int depth_) {
    if(depth_ == 5) return cnt_tile();
    int ret = 0;

    for(int k=1;k<=6;k++) {
        int tmp[10][10];
        rep(i,10) rep(j,10) tmp[i][j] = tile[i][j];
        fill_tile(k);
        ret = max(ret,dfs(depth_+1));
        rep(i,10) rep(j,10) tile[i][j] = tmp[i][j];
    }

    return ret;
}
void solve() {
    rep(i,10) rep(j,10) tile[i][j] = 0;
    rep(i,h) rep(j,w) cin>>tile[i][j];
    cout<<dfs(0)<<endl;

}
int main() {
    while(cin>>h>>w>>c) {
        if(h+w+c==0) return 0;
        solve();
    }

    return 0;
}
