#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int dx[] = {0,1,1,0,-1,-1};
int dy[] = {1,1,0,-1,-1,0};
int t,n;
typedef pair<int,int> P;
const int C = 60;
const int MAX_N=130;
const int INF = 100000;

void solve() {
    int dist[MAX_N][MAX_N];
    bool ok[MAX_N][MAX_N];
    rep(i,MAX_N) rep(j,MAX_N) dist[i][j]=INF,ok[i][j]=true;
    int x,y;
    rep(i,n) {
        cin>>x>>y;
        x+=C;
        y+=C;
        ok[x][y]=false;
        
    }
    queue<P> que;
    cin>>x>>y;
    x+=C;
    y+=C;
    que.push(P(x,y));
    dist[x][y]=0;

    int ans = 0;
    while(que.size()) {
        P p = que.front(); que.pop();
        int x = p.first;
        int y = p.second;
        rep(i,6) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(ok[nx][ny] && dist[nx][ny] == INF) {
                dist[nx][ny] = dist[x][y]+1;
                que.push(P(nx,ny));
            }
        }
    }
    rep(i,MAX_N) rep(j,MAX_N) if(dist[i][j]<=t) ans++;
    cout<<ans<<endl;

}

int main() {
    while(cin>>t>>n) {
        if(t+n==0) return 0;
        solve();
    }
    return 0;
}
