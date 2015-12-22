#include <iostream>
#include <cstdio>
#include <queue>

#define rep(i,n) for(int i=0;i<(n);i++)
#define fr first
#define sc second
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};

using namespace std;
typedef pair<int,int> P;
int W,H;
string maze[100];
const int INF=1e9;

void solve() {
    int dp[100][100];
    rep(y,100) rep(x,100) dp[y][x]=INF;
    getchar();
    rep(y,2*H-1) getline(cin,maze[y]);

    queue<P> que;
    que.push(P(0,0));
    dp[0][0]=0;
    while(que.size()) {
        P p=que.front(); que.pop();
        rep(k,4) {
            int ny=p.fr+dy[k];
            int nx=p.sc+dx[k];
            int ny2=ny+dy[k];
            int nx2=nx+dx[k];
            if(!(0<=ny2&&ny2<2*H-1)) continue;
            if(!(0<=nx2&&nx2<2*W-1)) continue;
            if(dp[ny2][nx2]!=INF) continue;
            if(maze[ny][nx]=='1') continue;

            //printf("(%d, %d) -> (%d, %d)\n",p.fr,p.sc,ny2,nx2);
            dp[ny2][nx2]=dp[p.fr][p.sc]+1;
            que.push(P(ny2,nx2));
        }
    }

    int ans=dp[2*H-2][2*W-2];
    if(ans==INF) ans=0;
    else ans++;
    cout<<ans<<endl;
}

int main() {
    while(cin>>W>>H) {
        if(!W) break;
        solve();
    }
    return 0;
}
