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

struct Edge {
    int to,cost,time;
};
struct State {
    int v,cost,time;
    bool operator<(const State &rhs) const {
        return time > rhs.time;
    }
};
int N,V;
int C;
int S[1503],T[1503],Y[1503],M[1503];
vector<Edge> G[51];
int dijk() {
    int d[51][302];
    rep(i,51) rep(j,302) d[i][j]=INF;
    rep(j,302) d[1][j]=0;
    priority_queue<State> que;
    que.push(State{1,0,0});
    while(que.size()) {
        State s=que.top(); que.pop();
        rep(i,G[s.v].size()) {
            Edge e=G[s.v][i];
            if(C>=s.cost+e.cost and d[e.to][s.cost+e.cost]>d[s.v][s.cost]+e.time) {
                d[e.to][s.cost+e.cost]=d[s.v][s.cost]+e.time;
                que.push(State{e.to,s.cost+e.cost,d[e.to][s.cost+e.cost]});
            }
        }
    }

    int ret=INF;
    ret = *min_element(d[N],d[N]+C+1);
    if(ret==INF) return -1;
    return ret;
}
int main() {
    cin>>N>>C>>V;
    rep(i,V) cin>>S[i];
    rep(i,V) cin>>T[i];
    rep(i,V) cin>>Y[i];
    rep(i,V) cin>>M[i];
    rep(i,V) {
        G[S[i]].push_back(Edge{T[i],Y[i],M[i]});
        //G[T[i]].push_back(Edge{S[i],Y[i],M[i]});
    }
    cout<<dijk()<<endl;
    return 0;
}

