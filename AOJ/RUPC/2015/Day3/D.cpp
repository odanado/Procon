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

struct Edge{
    int to,cost;
    Edge(int to,int cost) :to(to),cost(cost){}
    Edge(){}
};
struct Lost{
    int s,t;
    Lost(int s,int t) :s(s),t(t){}
    Lost(){}
};
struct Vertex {
    int v;
    int bit1,bit2;
    Vertex(int v,int bit1,int bit2) :
        v(v),bit1(bit1),bit2(bit2){}
    Vertex(){}
    bool operator<(const Vertex rth) const {
        const Vertex &lth = *this;
        return lth.v<rth.v ||
            (!(rth.v<lth.v)&&lth.bit1<rth.bit1) ||
            (!(rth.v<lth.v)&&!(rth.bit1<lth.bit1)&&lth.bit2<rth.bit2);

    }

};
struct State{
    int cost;
    Vertex v;
    State(int cost,Vertex v): cost(cost),v(v){}
    State(){}

    bool operator>(const State rth) const {
        return this->cost>rth.cost;
    }
};
int n,m,k,p;
vector<Edge> G[1003];
Lost lost[10];
map<Vertex,int> dp;

int dijk() {
    rep(a,n) rep(b,1<<6) rep(c,1<<6) dp[Vertex(a,b,c)]=INF;
    dp[Vertex(p,0,0)]=0;

    priority_queue<State,vector<State> ,greater<State> > que;
    que.push(State(0,Vertex(p,0,0)));

    while(que.size()) {
        State s=que.top(); que.pop();
        int v=s.v.v;
        int bit1=s.v.bit1;
        int bit2=s.v.bit2;
        Vertex cur;

        cur=s.v;
        if(cur.bit2+1==(1<<k)) break;
        if(dp[cur]>s.cost) continue;
        // printf("%d %d %d : %d\n",cur.v,cur.bit1,cur.bit2,dp[cur]);
        rep(i,G[v].size()) {
            Edge e=G[v][i];
            Vertex next;
            rep(a,k) {
                if(lost[a].s==e.to) {
                    next=Vertex(e.to,bit1|1<<a,bit2);
                    if(dp[next]>dp[cur]+e.cost) {
                        dp[next]=dp[cur]+e.cost;
                        que.push(State(dp[next],next));
                    }
                }
                if(lost[a].t==e.to&&(bit1>>a)&1) {
                    next=Vertex(e.to,bit1,bit2|1<<a);
                    if(dp[next]>dp[cur]+e.cost) {
                        dp[next]=dp[cur]+e.cost;
                        que.push(State(dp[next],next));
                    }
                }
            }
            next=Vertex(e.to,bit1,bit2);
            if(dp[next]>dp[cur]+e.cost) {
                dp[next]=dp[cur]+e.cost;
                que.push(State(dp[next],next));
            }
        }
    }

    int ans=INF;
    rep(i,n) {
        Vertex v=Vertex(i,(1<<k)-1,(1<<k)-1);
        // printf("%d %d %d : %d\n",v.v,v.bit1,v.bit2,dp[v]);
        if(dp.count(v)) ans=min(ans,dp[v]);
    }

    return ans;
}

int main() {
    cin>>n>>m>>k>>p;
    p--;
    rep(i,m) {
        int x,y,w;
        cin>>x>>y>>w;
        x--,y--;
        G[x].pb(Edge(y,w));
        G[y].pb(Edge(x,w));
    }
    rep(i,k) {
        int s,t;
        cin>>s>>t;
        s--,t--;
        lost[i].s=s;
        lost[i].t=t;
    }
    int ans=dijk();
    if(ans==INF) cout<<"Cannot deliver"<<endl;
    else cout<<ans<<endl;
    return 0;
}

