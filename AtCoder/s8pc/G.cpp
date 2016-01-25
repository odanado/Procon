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
#include <tuple>

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
using namespace std;
typedef long long ll;
const ll INF=1e18;
typedef pair<ll,ll> P;

template<class T>
bool chmin(T &a, const T &b) {
    if(a>b) {
        a=b;
        return true;
    }
    return false;
}

struct Edge {
    ll to,cost;
    ll time;
    Edge(ll to=0,ll cost=0,ll time=0):
        to(to),cost(cost),time(time){}
};
vector<Edge> G[20];
struct Node {
    int S;
    int v;
    Node(int S=0,int v=0):
        S(S),v(v){}
    bool operator<(const Node &rhs) const {
        return tie(S,v) < tie(rhs.S,rhs.v);
    }
};
struct State : public Node {
    ll time;
    ll cnt;
    State(ll time=0,ll cnt=0,int S=0,int v=0):
        time(time), cnt(cnt), Node(S,v){}
    bool operator<(const State &rhs) const {
        return time > rhs.time;
    }
};
int N,M;
int main() {
    cin>>N>>M;
    rep(i,M) {
        ll a,b,d,t;
        cin>>a>>b>>d>>t;
        a--,b--;
        G[a].pb(Edge(b,d,t));
        G[b].pb(Edge(a,d,t));
    }

    map<Node,P> d;
    priority_queue<State> que;
    que.push(State(0,1,0,0));
    d[Node(0,0)]=P(0,1);
    ll mini=INF;
    while(que.size()) {
        State s=que.top(); que.pop();
        Node nowNode(s.S,s.v);
        //printf("debug: %lld %lld %d %d\n",s.time,s.cnt,s.S,s.v);
        if(s.S+1==(1<<N)&&s.v==0) chmin(mini,s.time);
        rep(i,G[s.v].size()) {
            Edge e=G[s.v][i];
            if(s.S>>e.to&1) continue;
            ll nextTime=s.time+e.cost;
            if(nextTime>e.time) continue;
            Node node=Node(s.S|1<<e.to,e.to);
            if(d.count(node)) {
                //printf("node: %d %d -> %d %d\n",s.S,s.v,node.S, node.v);
                //printf("debug: %lld < %lld?\n",d[node].first,nextTime);
                if(chmin(d[node].first, nextTime)) {
                    d[node].second=d[nowNode].second;
                    //printf("cost: %lld %lld -> %lld %lld\n",d[nowNode].first,d[nowNode].second,d[node].first, d[node].second);
                    que.push(State(d[node].first,d[node].second, node.S, node.v));
                }
                else if(d[node].first==nextTime) {
                    d[node].second+=d[nowNode].second;
                }
                continue;
            }
            d[node].first=nextTime;
            d[node].second=d[nowNode].second;
            //printf("node: %d %d -> %d %d\n",s.S,s.v,node.S, node.v);
            //printf("cost: %lld %lld -> %lld %lld\n",d[nowNode].first,d[nowNode].second,d[node].first, d[node].second);
            que.push(State(d[node].first,d[node].second, node.S, node.v));
        }
    }
    if(mini==INF) {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    P p=d[Node((1<<N)-1,0)];
    cout<<p.fr<<" "<<p.sc<<endl;
    return 0;
}

