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
typedef long long ll;

template<class T>
bool chmin(T &a, T b) {
    if(b<a) {
        a=b;
        return true;
    }
    return false;
}

ll H,W,L;
string maze[110];
struct State {
    int dir,y,x;
    ll cnt;
    State(int dir,int y,int x,ll cnt) :
        dir(dir),y(y),x(x),cnt(cnt){}
};

void solve(P &ans_p,int &ans_dir) {
    queue<State> que;
    map<char,int> dir;
    dir['E']=0;
    dir['S']=1;
    dir['W']=2;
    dir['N']=3;
    ll d[4][110][110];
    rep(y,110) rep(x,110) d[0][y][x]=d[1][y][x]=d[2][y][x]=d[3][y][x]=INF;
    rep(y,H) rep(x,W) if(maze[y][x]!='.'&&maze[y][x]!='#') {
        d[dir[maze[y][x]]][y][x]=0;
        que.push(State(dir[maze[y][x]],y,x,0));
    }

    while(que.size()) {
        State s=que.front(); que.pop();
        //printf("%d %d %d : %d\n",s.dir,s.y,s.x,s.cnt);
        if(L==s.cnt) {
            ans_p=P(s.y,s.x);
            ans_dir=s.dir;
            return;
        }
        if(d[s.dir][s.y][s.x]!=s.cnt) {
            //printf("%d %d %d : %d %d\n",s.dir,s.y,s.x,s.cnt,d[s.dir][s.y][s.x]);
            ll diff=abs(s.cnt-d[s.dir][s.y][s.x]);
            ll t=(L-s.cnt)/diff;
            if(t>0&&diff>0) {
                s.cnt+=(t-1)*diff;
            }
            //printf("\t%d\n",s.cnt);
        }
        int ny=s.y+dy[s.dir];
        int nx=s.x+dx[s.dir];
        if(!(0<=ny&&ny<H&&0<=nx&&nx<W)) {
            que.push(State((s.dir+1)%4,s.y,s.x,s.cnt));
            chmin(d[(s.dir+1)%4][s.y][s.x],s.cnt);
        }
        else {
            if(maze[ny][nx]=='#') {
                que.push(State((s.dir+1)%4,s.y,s.x,s.cnt));
                chmin(d[(s.dir+1)%4][s.y][s.x],s.cnt);
            }
            else {
                que.push(State(s.dir,ny,nx,s.cnt+1));
                chmin(d[s.dir][ny][nx],s.cnt+1);
            }
        }
    }
}

int main() {
    while(cin>>H>>W>>L) {
        if(H==0) break;
        rep(y,H) cin>>maze[y];
        P ans;
        int dir=-1;
        solve(ans,dir);
        if(dir==-1) int a=1/0;
        char d;
        if(dir==0) d='E';
        if(dir==1) d='S';
        if(dir==2) d='W';
        if(dir==3) d='N';
        printf("%d %d %c\n",ans.fr+1,ans.sc+1,d);
    }
    return 0;
}

