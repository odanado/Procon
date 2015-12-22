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
using namespace std;
typedef pair<int ,int > P;
typedef pair<P ,int > Pi;
typedef long long ll;

int w,h;
char s[61][31];
int d[61][31][2];
template<class T>
bool chmin(T &a, const T &b) {
    if(a>b) {
        a=b;
        return true;
    }
    return false;
}

void bfs(int y,int x,int foot) {
    d[y][x][foot]=0;
    queue<Pi> que;
    que.push(Pi(P(y,x),foot));
    while(que.size()) {
        Pi p=que.front();
        que.pop();
        int cur_y=p.fr.fr;
        int cur_x=p.fr.sc;
        int cur_foot=p.sc;
        int a[]={0,2,1,0};
        //printf("[debug] %d %d %d\n",cur_y,cur_x,cur_foot);

        for(int dx=1;dx<=3;dx++) {
            for(int dy=-a[dx];dy<=a[dx];dy++) {
                int ny=dy+cur_y;
                int nx=dx+cur_x;
                if(cur_foot==1) {
                    nx=cur_x-dx;
                }
                if(ny<0 || nx<0) continue;
                if(h<=ny || w<=nx) continue;
                if(s[ny][nx] == 'X') continue;
                if(s[ny][nx] == 'S') continue;

                //printf("[debug] %d %d : %d -> %d %d : %d\n",cur_y,cur_x,d[cur_y][cur_x][cur_foot],ny,nx,d[ny][nx][cur_foot^1]);
                if(s[ny][nx]=='T') {
                    chmin(d[ny][nx][cur_foot^1],d[cur_y][cur_x][cur_foot]);
                }
                else if(chmin(d[ny][nx][cur_foot^1],d[cur_y][cur_x][cur_foot]+s[ny][nx]-'0')) {
                    que.push(Pi(P(ny,nx),cur_foot^1));
                }
            }
        }

    }
}

void solve() {
    rep(y,h) rep(x,w) cin>>s[y][x];
    rep(y,h) rep(x,w) d[y][x][0]=d[y][x][1]=INF;
    rep(y,h) rep(x,w) if(s[y][x]=='S') {
        bfs(y,x,0);
        bfs(y,x,1);
    }
    int ans=INF;
    rep(y,h) rep(x,w) if(s[y][x]=='T') rep(i,2) chmin(ans,d[y][x][i]);

    if(ans==INF) ans=-1;
    cout<<ans<<endl;
}

int main() {
    while(cin>>w>>h) {
        if(!w) break;
        solve();
    }
    return 0;
}

