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
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
using namespace std;
typedef pair<int ,int > P;
typedef long long ll;
vector<int> G[20*20*100];
int match[20*20*100];
bool used[20*20*100];

struct BipartiteMatching {
    int V;
    BipartiteMatching(int V):V(V){
    }

    void add_edge(int u,int v) {
        G[u].push_back(v);
        G[v].push_back(u);
    }

    bool dfs(int v) {
        used[v]=true;
        for(int i=0;i<G[v].size();i++){
            int u=G[v][i];
            int w=match[u];
            if(w<0||!used[w]&&dfs(w)) {
                match[v]=u;
                match[u]=v;
                return true;
            }
        }
        return false;
    }

    int operator() () {
        int res=0;
        memset(match,-1,sizeof(match));
        for(int v=0;v<V;v++){
            if(match[v]<0) {
                memset(used,0,sizeof(used));
                if(dfs(v)) res++;
            }
        }
        return res;
    }
};
int K;
char field[20][20];

int X,Y;
vector<int> dX,dY;
vector<int> pX,pY;
int dist[20][20][20][20];

bool C(int t) {
    int d=dX.size();
    int p=pX.size();

    int V=t*d+p;
    rep(i,V) G[i].clear();
    BipartiteMatching bm(V);

    rep(i,d) rep(j,p) if(dist[dX[i]][dY[i]][pX[j]][pY[j]]>=0) {
        for(int k=dist[dX[i]][dY[i]][pX[j]][pY[j]];k<=t;k++) bm.add_edge((k-1)*d+i,t*d+j);
    }

    return p==bm();
}

void bfs(int x,int y,int d[20][20]) {
    queue<int> qx,qy;
    d[x][y]=0;
    qx.push(x);
    qy.push(y);

    while(qx.size()) {
        int x=qx.front();qx.pop();
        int y=qy.front();qy.pop();

        rep(i,4) {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(!(0<=nx&&nx<X)) continue;
            if(!(0<=ny&&ny<Y)) continue;
            if(field[nx][ny]=='.'&&d[nx][ny]<0) {
                d[nx][ny]=d[x][y]+1;
                qx.push(nx);
                qy.push(ny);
            }
        }
    }
}

void solve() {
    rep(i,20*20*100) G[i].clear();
    scanf("%d %d",&X,&Y);
    for(int i = 0; i < X; i++){
        scanf("%s", field[i]);
    }

    int n=X*Y;
    dX.clear(); dY.clear();
    pX.clear(); pY.clear();
    memset(dist,-1,sizeof(dist));

    rep(x,X) rep(y,Y) {
        if(field[x][y]=='D') {
            dX.push_back(x);
            dY.push_back(y);
            bfs(x,y,dist[x][y]);
        }
        else if(field[x][y]=='.') {
            pX.pb(x);
            pY.pb(y);
        }
    }

    int lb=-1,ub=n+1;
    while(ub-lb>1) {
        int mid=(lb+ub)/2;
        if(C(mid)) ub=mid;
        else lb=mid;
    }

    if(ub>n) printf("impossible\n");
    else printf("%d\n",ub);

}

int main() {
    scanf("%d",&K);
    rep(i,K) solve();
    return 0;
}

