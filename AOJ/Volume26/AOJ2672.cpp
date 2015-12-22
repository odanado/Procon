#include <iostream>
#include <algorithm>
#include <queue>

typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
const ll INF=1e12;

using namespace std;
template<class T>
bool chmin(T &a, const T &b) {
    if(a>b) {
        a=b;
        return true;
    }

    return false;
}
int n,m,k,p;
int s[10],t[10];

struct State {

    int v;
    ll cost;
    // 拾ったか,届けたか
    int S1,S2;

    bool operator<(const State &rhs) const {
        return cost>rhs.cost;
    }
};
struct Edge {
    int to,cost;
};

vector<Edge> G[1003];

ll dp[1003][1<<6][1<<6];
ll dijk() {
    rep(i,1003) rep(j,1<<6) rep(k,1<<6) dp[i][j][k]=INF;
    priority_queue<State> que;
    int tmp=find(s,s+k,p)-s;
    if(tmp!=k) {
        dp[p][1<<tmp][0]=0;
        que.push(State{p,0,1<<tmp,0});
    }
    else {
        dp[p][0][0]=0;
        que.push(State{p,0,0,0});
    }


    while(que.size()) {
        State st=que.top(); que.pop();
        int v=st.v;
        int S1=st.S1;
        int S2=st.S2;
        ll cost=st.cost;

        //printf("%d : %d %d %lld\n",v,S1,S2,cost);
        rep(i,G[v].size()) {
            Edge e=G[v][i];
            //printf("[debug] %d -> %d : %d\n",v,e.to,e.cost);
            int n_S1=S1,n_S2=S2;
            int pos_s=find(s,s+k,e.to)-s;
            int pos_t=find(t,t+k,e.to)-t;

            if(pos_s!=k) n_S1=S1|1<<pos_s;
            if(pos_t!=k&&S1>>pos_t&1) n_S2=S2|1<<pos_t;

            if(chmin(dp[e.to][n_S1][n_S2],dp[v][S1][S2]+e.cost)) {
                que.push(State{e.to,dp[e.to][n_S1][n_S2],n_S1,n_S2});
            }
        }
    }

    ll ret=INF;
    rep(i,n) chmin(ret,dp[i][(1<<k)-1][(1<<k)-1]);

    return ret;
}

int main() {
    cin>>n>>m>>k>>p;
    p--;
    rep(i,m) {
        int x,y,w;
        cin>>x>>y>>w;
        x--,y--;
        G[x].push_back(Edge{y,w});
        G[y].push_back(Edge{x,w});

    }
    rep(i,k) cin>>s[i]>>t[i];
    rep(i,k) s[i]--,t[i]--;

    ll ans=dijk();
    if(ans==INF) cout<<"Cannot deliver"<<endl;
    else cout<<ans<<endl;

    return 0;
}
