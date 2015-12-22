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
typedef pair<P,P> PP;
typedef long long ll;
 
 
int W,H;
string roomL[55],roomR[55];
 
bool range_check(int y,int x) {
    if(!(0<=y&&y<H)) return false;
    if(!(0<=x&&x<W)) return false;
 
    return true;
}
 
bool visited[55][55][55][55];
bool ok(P len,P rin) {
    memset(visited,0,sizeof(visited));
    visited[len.fr][len.sc][rin.fr][rin.sc]=true;
    queue<PP> que;
    que.push(PP(len,rin));
 
    while(que.size()) {
        PP pp=que.front(); que.pop();
        P next_len=pp.fr;
        P next_rin=pp.sc;
 
        //printf("[debug] %d %d %d %d\n",next_len.fr,next_len.sc,next_rin.fr,next_rin.sc);
 
        if(roomL[next_len.fr][next_len.sc]=='%' && roomR[next_rin.fr][next_rin.sc]=='%') {
            return true;
        }
        if(roomL[next_len.fr][next_len.sc]=='%' || roomR[next_rin.fr][next_rin.sc]=='%') {
            //visited[next_len.fr][next_len.sc][next_rin.fr][next_rin.sc]=false;
            continue;
        }
        rep(i,4) {
            next_len=pp.fr;
            next_rin=pp.sc;
 
            if(range_check(next_len.fr+dy[i],next_len.sc+dx[i]) && roomL[next_len.fr+dy[i]][next_len.sc+dx[i]]!='#') {
                next_len.fr+=dy[i];
                next_len.sc+=dx[i];
            }
            if(range_check(next_rin.fr+dy[i],next_rin.sc-dx[i]) && roomR[next_rin.fr+dy[i]][next_rin.sc-dx[i]]!='#') {
                next_rin.fr+=dy[i];
                next_rin.sc-=dx[i];
            }
 
            if(!visited[next_len.fr][next_len.sc][next_rin.fr][next_rin.sc]) {
                visited[next_len.fr][next_len.sc][next_rin.fr][next_rin.sc]=true;
                que.push(PP(next_len,next_rin));
            }
        }
    }
 
    return false;
}
 
void solve() {
    rep(y,55) roomL[y]=roomR[y]=string('#',55);
    rep(y,H) cin>>roomL[y]>>roomR[y];
    P len,rin;
    rep(y,H) rep(x,W) {
        if(roomL[y][x]=='L') len=P(y,x);
        if(roomR[y][x]=='R') rin=P(y,x);
    }
    if(ok(len,rin)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
 
int main() {
    while(cin>>W>>H) {
        if(!W) break;
        solve();
    }
    return 0;
}
