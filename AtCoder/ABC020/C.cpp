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

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
using namespace std;
typedef pair<int ,int > P;
typedef long long ll;
const ll INF=1e18;

int H,W,T;
string s[22];
P S,G;
ll bfs(ll x) {

    queue<P> que;
    que.push(S);

    ll dist[22][22];
    rep(i,22) rep(j,22) dist[i][j]=INF;

    dist[S.fr][S.sc]=0;
    while(que.size()) {
        P p=que.front(); que.pop();
        rep(i,4) {
            int ny=dy[i]+p.fr;
            int nx=dx[i]+p.sc;
            if(!(0<=ny&&ny<H)) continue;
            if(!(0<=nx&&nx<W)) continue;
            ll cost=1;
            if(s[ny][nx]=='#') cost=x;
            if(dist[ny][nx]>dist[p.fr][p.sc]+cost) {
                dist[ny][nx]=dist[p.fr][p.sc]+cost;
                que.push(P(ny,nx));
            }
        }
    }
    return dist[G.fr][G.sc];
}
int main() {
    cin>>H>>W>>T;
    rep(i,H) {
        cin>>s[i];
    }
    rep(i,H) rep(j,W) if(s[i][j]=='S') S=P(i,j);
    rep(i,H) rep(j,W) if(s[i][j]=='G') G=P(i,j);
    ll l,r;
    l=1;
    r=1e15;
    while(r-l>1) {
        ll mid=(r+l)/2;
        if(bfs(mid)<=T) l=mid;
        else r=mid;
    }
    cout<<l<<endl;

    return 0;
}

