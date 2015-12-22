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

int R,C;
int rs,cs;
int rg,cg;
int N;
char grid[50][50];

void fill(int r,int c,int h,int w) {
    for(int y=r;y<r+h;y++) {
        for(int x=c;x<c+w;x++) {
            grid[y][x] = '#';
        }
    }
}

bool bfs() {
    if(grid[rs][cs] == '.') return false;
    bool flag[50][50];
    rep(i,50) rep(j,50) flag[i][j] = false;

    queue<P> que;
    que.push(P(rs,cs));
    while(que.size()) {
        P p = que.front();
        que.pop();
        if(flag[p.fr][p.sc]) continue;
        // printf("[debug] %d,%d,%d\n", p.fr,p.sc,flag[p.fr][p.sc]);
        flag[p.fr][p.sc]=true;
        if(p.fr==rg&&p.sc==cg) return true;
        rep(i,4) {
            int ny = p.fr+dy[i];
            int nx = p.sc+dx[i];
            // printf("[debug] %d,%d\n",ny,nx);
            if(!(0<=ny&&ny<=48)) continue;
            if(!(0<=nx&&nx<=48)) continue;
            if(grid[ny][nx] == '.') continue;
            if(flag[ny][nx]) continue;
            que.push(P(ny,nx));
        }
    }

    return false;
}

int main() {
    rep(i,50) rep(j,50) grid[i][j]='.';
    cin>>R>>C;
    cin>>rs>>cs;
    cin>>rg>>cg;
    rs--; cs--;
    rg--; cg--;
    cin>>N;
    rep(i,N) {
        int r,c,h,w;
        cin>>r>>c>>h>>w;
        r--;
        c--;
        fill(r,c,h,w);
    }
    if(bfs()) {
        cout<<"YES"<<endl;
    }
    else {
        cout<<"NO"<<endl;
    }
    return 0;
}

