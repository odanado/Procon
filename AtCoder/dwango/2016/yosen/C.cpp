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

const int INF=1e18;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
using namespace std;
typedef pair<int ,int > P;
typedef long long ll;

template<class T>
bool chmin(T &a, const T &b) {
    if(a>b) {
        a=b;
        return true;
    }
    return false;
}

int N,M,src,dst;

struct State {
    ll v;
    bool flag;
    ll cost;
    bool operator<(const State &rhs) const {
        return cost > rhs.cost;
    }
};

struct Edge {
    ll to,cost;
    ll last,lcost;
    Edge(ll to=0,ll cost=0,ll last=0,ll lcost=0) :
        to(to), cost(cost), last(last), lcost(lcost){}
};


int s[30004],w[30004];
ll d[30004];
ll d1[30004];
vector<Edge> G[30004];
void addEdge(ll from,ll to,ll cost,ll last,ll lcost) {
    //printf("debug: %d->%d:%d, %d->%d:%d\n",from,to,cost,from,last,lcost);
    G[from].pb(Edge(to,cost,last,lcost));
}
bool ok(ll t) {
    rep(i,30004) d1[i]=INF;
    priority_queue<State> que;
    d1[src]=0;
    que.push(State{src,false,0});
    while(que.size()) {
        State s=que.top(); que.pop();
        //printf("debug: %d %d %d\n",t,s.v,s.cost);
        for(auto e:G[s.v]) {
            //printf("debug: %d->%d(%d): %d(%d+%d+%d)\n",s.v,e.to,e.last,d1[s.v]+e.lcost+d[e.last],d1[s.v],e.lcost,d[e.last]);
            if(d1[s.v]+e.lcost+d[e.last]>t) continue;
            if(chmin(d1[e.to],d1[s.v]+e.cost)) {
                que.push(State{e.to,s.flag,d1[e.to]});
            }
        }
    }

    return d1[dst]<=t;
}
int main() {
    cin>>N>>M>>src>>dst;
    rep(_,M) {
        int l;
        cin>>l;
        rep(i,l) cin>>s[i];
        rep(i,l-1) cin>>w[i];
        ll sum=0;
        rep(i,l-1) sum+=w[i];
        rep(i,l-1) {
            addEdge(s[i],s[i+1],w[i],s[l-1],sum);
            sum-=w[i];
        }
        sum=0;
        rep(i,l-1) sum+=w[i];
        for(int i=l-2;i>=0;i--) {
            addEdge(s[i+1],s[i],w[i],s[0],sum);
            sum-=w[i];
        }
    }

    rep(i,30004) d[i]=INF;
    d[dst]=0;
    priority_queue<State> que;
    que.push(State{dst,false,0});
    while(que.size()) {
        State s=que.top(); que.pop();
        //printf("debug: %d %d %d\n",s.v,s.flag,s.cost);
        for(auto e:G[s.v]) {
            if(chmin(d[e.to],d[s.v]+e.cost)) {
                que.push(State{e.to,s.flag,d[e.to]});
            }
        }
    }
    ll lb=0,ub=INF;
    while(ub-lb>1) {
        ll mid=(ub+lb)/2;
        if(ok(mid)) ub=mid;
        else lb=mid;
    }
    cout<<ub<<endl;
    return 0;
}

