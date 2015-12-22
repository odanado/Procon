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

struct edge {
    int to,cost;
    edge(int to,int cost) :
        to(to),cost(cost){}
};
struct state {
    int time,idx,ice_time;
    state(int time,int idx,int ice_time) :
        time(time),idx(idx),ice_time(ice_time){}
    bool operator>(const state& rth) const {
        this->time>rth.time;
    }
};
vector<edge> G[102];

int N,M,L,K,A,H;
bool ice[102];

// A->H
int dijk() {
    int d[102][102];
    rep(i,102) rep(j,102) d[i][j]=INF;
    d[A][M]=0;

    priority_queue<state,vector<state>,greater<state> > que;
    que.push(state(0,A,M));

    while(que.size()) {
        state s=que.top(); que.pop();
        int v=s.idx;
        int ice_time=s.ice_time;
        if(d[v][ice_time]<s.time) continue;

        if(ice[v]) {
            rep(i,G[v].size()) {
                edge e=G[v][i];
                for(int t=ice_time;t<=M;t++) {
                    if(t-e.cost>=0 && d[v][ice_time]+e.cost+t-ice_time<d[e.to][t-e.cost]) {
                        d[e.to][t-e.cost]=d[v][ice_time]+e.cost+t-ice_time;
                        que.push(state(d[e.to][t-e.cost],e.to,t-e.cost));
                    }
                }
            }
        }
        else {
            rep(i,G[v].size()) {
                edge e=G[v][i];
                if(ice_time-e.cost>=0 && d[v][ice_time]+e.cost<d[e.to][ice_time-e.cost]) {
                    d[e.to][ice_time-e.cost]=d[v][ice_time]+e.cost;
                    que.push(state(d[e.to][ice_time-e.cost],e.to,ice_time-e.cost));
                }
            }
        }
    }
    int res=INF;
    rep(i,102) res=min(res,d[H][i]);

    return res;

}

void solve() {
    rep(i,102) ice[i]=false;
    rep(i,102) G[i].clear();
    rep(i,L) {
        int a; cin>>a;
        ice[a]=true;
    }
    rep(i,K) {
        int a,b,c;
        cin>>a>>b>>c;
        G[a].pb(edge(b,c));
        G[b].pb(edge(a,c));

    }

    int ans=dijk();
    if(ans==INF) cout<<"Help!"<<endl;
    else cout<<ans<<endl;

}

int main() {
    while(cin>>N>>M>>L>>K>>A>>H) {
        if(N==0) break;
        solve();
    }
    return 0;
}

