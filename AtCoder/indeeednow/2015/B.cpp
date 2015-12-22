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
int dy[]={-1,-1,0,1,1 ,0};
int dx[]={0 , 1,1,1,0,-1};
using namespace std;
typedef pair<int ,int > P;
typedef long long ll;

int R,C;
char a[102][102];
int dist[102][102];
P s,t;

int bfs() {
    rep(i,102) rep(j,102) dist[i][j]=INF;
    queue<P> que;
    que.push(s);
    dist[s.fr][s.sc]=0;

    while(que.size()) {
        P p=que.front(); que.pop();
        printf("%d %d %c\n",p.fr,p.sc,a[p.fr][p.sc]);
        // cout<<p.fr<<","<<p.sc<<endl;
        rep(i,6) {
            int ny=p.fr+dy[i];
            int nx=p.sc+dx[i];
            if(!(0<=ny&&ny<R)) continue;
            if(!(0<=nx&&nx<C)) continue;
            int cost=a[ny][nx]-'0';
            if(a[ny][nx]=='t') cost=0;
            if(dist[p.fr][p.sc]+cost<dist[ny][nx]) {
                dist[ny][nx]=dist[p.fr][p.sc]+cost;
                que.push(P(ny,nx));
            }
        }
    }

    return dist[t.fr][t.sc];
}

int main() {
    cin>>R>>C;
    rep(i,R) rep(j,C) cin>>a[i][j];
    rep(i,R) rep(j,C) if(a[i][j]=='s') s=P(i,j);
    rep(i,R) rep(j,C) if(a[i][j]=='t') t=P(i,j);

    cout<<bfs()<<endl;
    return 0;
}

