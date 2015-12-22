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
const ll INF=1e14;
int H,W,T;
string maze[11];

bool ok(P s,P g,ll x) {
    queue<P> que;
    que.push(s);
    ll d[11][11];
    rep(i,11) rep(j,11) d[i][j]=INF;
    d[s.fr][s.sc]=0;

    while(que.size()) {
        P p=que.front(); que.pop();
        rep(i,4) {
            int ny=p.fr+dy[i];
            int nx=p.sc+dx[i];
            if(!(0<=ny&&ny<H)) continue;
            if(!(0<=nx&&nx<W)) continue;
            ll cost=1;
            if(maze[ny][nx]=='#') cost=x;
            if(d[ny][nx]>d[p.fr][p.sc]+cost) {
                d[ny][nx]=d[p.fr][p.sc]+cost;
                que.push(P(ny,nx));
            }
        }
    }

    //printf("%d %d\n",x,d[g.fr][g.sc]);
    return d[g.fr][g.sc]<=T;
}

int main() {
    cin>>H>>W>>T;
    rep(i,H) cin>>maze[i];
    P s,g;
    rep(y,H) rep(x,W) if(maze[y][x]=='S') s=P(y,x);
    rep(y,H) rep(x,W) if(maze[y][x]=='G') g=P(y,x);

    ll lb=-1,ub=INF;

    while(ub-lb>1) {
        ll mid=(lb+ub)/2;
        if(!ok(s,g,mid)) ub=mid;
        else lb=mid;
    }

    cout<<lb<<endl;


    return 0;
}

