#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <climits>

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

const int INF=100000000;
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
using namespace std;
typedef pair<int ,int > P;
typedef long long ll;

const int MAX=1010;
int caves[MAX][MAX];
bool is_prime[MAX*MAX];
void init() {
    int y=MAX/2;
    int x=MAX/2;

    int d=0;
    int k=1;
    while(1) {
        caves[y][x]=k;
        k++;

        y+=dy[d];
        x+=dx[d];
        if(y<0) break;
        if(x<0) break;
        if(MAX<=y) break;
        if(MAX<=x) break;

        if(caves[y+dy[(d+1)%4]][x+dx[(d+1)%4]]==0) d=(d+1)%4;
    }
    
    rep(i,MAX*MAX) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<MAX*MAX;i++) {
        if(is_prime[i]) for(int j=i+i;j<MAX*MAX;j+=i) is_prime[j]=false;
    }

}
int m,n;
int dp[MAX][MAX];
typedef pair<P,int> Pi;
int maxi[MAX*MAX];

int bfs(int y,int x) {
    dp[y][x]=is_prime[caves[y][x]];
    // dp[y][x]=0:
    int t=0;
    if(is_prime[caves[y][x]]) t=caves[y][x];
    queue<Pi> que;
    que.push(Pi(P(y,x),t));

    while(que.size()) {
        Pi p=que.front();
        y=p.fr.fr;
        x=p.fr.sc;
        que.pop();
        maxi[dp[y][x]]=max(maxi[dp[y][x]],p.sc);

        t=p.sc;
        if(is_prime[caves[y][x]]) t=max(t,caves[y][x]);

        // printf("[debug] %d %d %d\n",caves[y][x],p.sc,dp[y][x]);

        int d[]={-1,0,1};
        rep(i,3) {
            int ny=y+1;
            int nx=x+d[i];
            if(!(0<=ny&&ny<MAX)) continue;
            if(!(0<=nx&&nx<MAX)) continue;
            if(m<caves[ny][nx]) continue;

            maxi[dp[ny][nx]]=max(maxi[dp[ny][nx]],t);

            if(dp[ny][nx]<dp[y][x]+is_prime[caves[ny][nx]]) {
                dp[ny][nx]=dp[y][x]+is_prime[caves[ny][nx]];

                que.push(Pi(P(ny,nx),t));

            }
        }
    }

    int ans=0,ans2=0;
    rep(y,MAX) rep(x,MAX) ans=max(ans,dp[y][x]);
    rep(y,MAX) rep(x,MAX) if(dp[y][x]==ans&&is_prime[caves[y][x]]) ans2=max(ans2,caves[y][x]);

    cout<<ans<<" "<<ans2<<endl;
    return 0;
}

void solve() {
    memset(dp,-1,sizeof(dp));
    memset(maxi,0,sizeof(maxi));
    P p;
    rep(y,MAX) rep(x,MAX) if(caves[y][x]==n) p=P(y,x);
    // int ans=dfs(p.fr,p.sc);

    bfs(p.fr,p.sc);
}

int main() {
    init();
    while(cin>>m>>n) {
        if(m+n==0) break;
        solve();
    }
    return 0;
}

