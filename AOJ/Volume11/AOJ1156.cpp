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
int dy[4]={0,1,0,-1};
using namespace std;
typedef pair<int ,int > P;
typedef pair<P,int> Pi;
typedef long long ll;

int w,h;
int board[31][31];
int c[4];

// dir : 右 0,下 1,左 2,上 3
P next(P p,int &dir,int cmd) {
    if(cmd==1) {
        dir++;
    }
    else if(cmd==2) {
        dir+=2;
    }
    else if(cmd==3) {
        dir--;
    }

    while(dir<0) dir+=4;
    dir%=4;
    p.fr+=dy[dir];
    p.sc+=dx[dir];

    return p;
}

int bfs() {
    map<Pi,int> d;
    queue<Pi> que;
    que.push(Pi(P(0,0),0));
    rep(y,h) rep(x,w) rep(k,4) d[Pi(P(y,x),k)]=INF;
    d[Pi(P(0,0),0)]=0;
    while(que.size()) {
        Pi p=que.front();
        que.pop();
        int y=p.fr.fr;
        int x=p.fr.sc;
        int dir=p.sc;
        int cmd=board[y][x];

        //printf("[debug] %d,%d,%d : %d\n",y,x,dir,d[p]);
        if(cmd!=4) {
            Pi next_p={next(p.fr,dir,cmd),0};
            next_p.sc=dir;

            if(0<=next_p.fr.fr<h && 0<=next_p.fr.sc<w && d[next_p]>d[p]) {
                d[next_p]=min(d[next_p],d[p]);
                que.push(next_p);
            }
        }
        rep(i,4) {
            dir=p.sc;
            Pi next_p={next(p.fr,dir,i),0};
            next_p.sc=dir;
            if(0<=next_p.fr.fr<h && 0<=next_p.fr.sc<w && d[next_p]>d[p]+c[i]) {
                d[next_p]=min(d[next_p],d[p]+c[i]);
                que.push(next_p);
            }
        }
    }
    int ret=INF;
    rep(i,4) if(d.count(Pi(P(h-1,w-1),i))) {
        //printf("%d %d\n",i,d[Pi(P(h-1,w-1),i)]);
        ret=min(ret,d[Pi(P(h-1,w-1),i)]);
    }

    return ret;
}
void solve() {
    rep(y,h) rep(x,w) cin>>board[y][x];
    rep(i,4) cin>>c[i];
    int ans=bfs();

    cout<<ans<<endl;
}
int main() {
    while(cin>>w>>h) {
        if(!w) break;
        solve();
    }
    return 0;
}

