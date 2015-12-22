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
typedef long long ll;

template<class T>
inline bool chmin(T& a, const T& b) {
    if(b<a) {
        a=b;
        return true;
    }

    return false;
}

struct Edge {
    int to,cost;
    int h,r;
    Edge(int to,int cost,int h,int r) :
        to(to),cost(cost),h(h),r(r){}
};
struct Passport{
    int len;
    int d;
    int S;
    int comps[10];
};

int N,M,H,K;
vector<Edge> G[102];
vector<Passport> pass;

typedef pair<int,pair<int,int> > Pi;
int d[102][30];
int dijk(int s,int t,int S) {
    typedef pair<int,int> P;
    rep(i,102) rep(j,30) d[i][j]=INF;
    d[s][0]=0;

    priority_queue<Pi,vector<Pi>,greater<Pi> > que;
    que.push(Pi(0,P(s,0)));

    while(que.size()) {
        Pi pi=que.top(); que.pop();
        int v=pi.sc.fr;
        int h=pi.sc.sc;

        rep(i,G[v].size()) {
            Edge e=G[v][i];
            int cost = e.cost;
            if((S>>e.r)&1) {
                cost=0;
            }

            if(h+e.h<=H && chmin(d[e.to][h+e.h],d[v][h]+cost)) {
                que.push(Pi(d[e.to][h+e.h],P(e.to,h+e.h)));
            }
        }
    }

    int ret=INF;
    rep(i,H+1) chmin(ret,d[t][i]);

    return ret;
}

int dp[300][1<<8];
int calc_dp() {
    dp[0][0]=0;
    // dp[i][S] i番目までSを作るときの最小コスト
    rep(i,pass.size()) rep(S,1<<8) {
        int d=pass[i].d;
        int S_n=S|pass[i].S;

        chmin(dp[i+1][S_n],dp[i][S]+d);
        chmin(dp[i+1][S],dp[i][S]);
    }

}

void solve() {
    rep(i,300) rep(j,1<<8) dp[i][j]=INF;
    int P;
    int s,t;
    rep(i,102) G[i].clear();
    pass.clear();
    rep(i,M) {
        int a,b,c,h,r;
        cin>>a>>b>>c>>h>>r;
        r--;
        G[a].pb(Edge(b,c,h,r));
        G[b].pb(Edge(a,c,h,r));
    }
    cin>>s>>t;
    cin>>P;
    pass.resize(P);
    rep(i,P) {
        int l,d;
        cin>>l>>d;
        pass[i].len=l;
        pass[i].d=d;
        int Set=0;
        rep(j,l) {
            int k;
            cin>>k;
            k--;
            Set|=1<<k;
            pass[i].S=Set;
        }
    }

    calc_dp();

    int ans=INF;
    // rep(i,1<<3) printf("%d %d\n",i,dp[2][i]);
    rep(S,1<<8) {
        chmin(ans, dijk(s,t,S)+dp[pass.size()][S]);
    }
    if(ans==INF) ans=-1;
    cout<<ans<<endl;

}

int main() {
    ios::sync_with_stdio(false);
    while(cin>>N>>M>>H>>K) {
        if(N+M+H+K==0) break;
        solve();
    }
    return 0;
}

