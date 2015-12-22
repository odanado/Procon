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

map<P,int> ids;
template<class T>
bool chmin(T &a,const T& b) {
    if(a>b) {
        a=b;
        return true;
    }
    return false;
}

int w,h;
string room[21];
int dist[12][12];
int to_id(P p) {
    if(!ids.count(p)) ids[p]=ids.size();

    return ids[p];
}

void bfs(P p) {
    int d[21][21];
    rep(i,21) rep(j,21) d[i][j]=INF;
    int s=to_id(p);
    queue<P> que;
    que.push(p);
    d[p.fr][p.sc]=0;

    while(que.size()) {
        int y=que.front().fr;
        int x=que.front().sc;
        que.pop();
        rep(i,4) {
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(ny<0||nx<0) continue;
            if(h<=ny||w<=nx) continue;
            if(d[ny][nx]!=INF) continue;
            if(room[ny][nx]=='x') continue;

            if(chmin(d[ny][nx],d[y][x]+1)) {
                if(room[ny][nx]=='*') {
                    //printf("%d,%d -> %d,%d : %d\n",p.fr,p.sc,ny,nx,d[ny][nx]);
                    dist[s][to_id(P(ny,nx))]=d[ny][nx];
                    dist[to_id(P(ny,nx))][s]=d[ny][nx];
                }
                que.push(P(ny,nx));
            }
        }
    }
}

void solve() {
    ids.clear();
    P s;
    vector<P> vec;
    rep(i,12) rep(j,12) dist[i][j]=INF;
    rep(y,h) cin>>room[y];
    rep(y,h) rep(x,w) {
        if(room[y][x]=='*') {
            vec.pb(P(y,x));
            bfs(P(y,x));
        }
        if(room[y][x]=='o') {
            s=P(y,x);
            bfs(s);
        }
    }
    sort(all(vec));

    int ans=INF;
    do {
        int t=dist[to_id(s)][to_id(vec[0])];
        rep(i,vec.size()) if(i) t+=dist[to_id(vec[i-1])][to_id(vec[i])];
        chmin(ans,t);
    }while(next_permutation(all(vec)));

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

