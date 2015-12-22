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

template<class T>
bool chmin(T &a, const T &b) {
    if(a>b) {
        a=b;
        return true;
    }
    return false;
}

int N,M,L;
struct Edge {
    int to,d,e;
};
struct Node {
    int v,cost,money;

    bool operator<(const Node& rhs) const {
        return cost>rhs.cost;
    }
};
vector<Edge> G[102];

void solve() {
    int dp[102][102];
    rep(i,102) rep(j,102) dp[i][j]=INF;
    rep(i,102) G[i].clear();

    dp[0][L]=0;
    rep(i,M) {
        int a,b,d,e;
        cin>>a>>b>>d>>e;
        a--;
        b--;
        G[a].push_back({b,d,e});
        G[b].push_back({a,d,e});
    }

    priority_queue<Node,vector<Node>> que;
    que.push({0,0,L});
    while(que.size()) {
        Node node=que.top();
        que.pop();
        int v=node.v;
        int money=node.money;

        //printf("[debug] %d %d %d : %d\n",v,node.cost,money,dp[v][money]);
        rep(i,G[v].size()) {
            Edge e=G[v][i];

            if(chmin(dp[e.to][money],dp[v][money]+e.e)) {
                que.push({e.to,dp[e.to][money],money});
            }
            if(money-e.d>=0 && chmin(dp[e.to][money-e.d],dp[v][money])) {
                que.push({e.to,dp[e.to][money-e.d],money-e.d});
            }

        }
    }

    int ans=INF;
    rep(i,L+1) chmin(ans,dp[N-1][i]);

    cout<<ans<<endl;

}

int main() {
    while(cin>>N>>M>>L) {
        if(!N) break;
        solve();
    }
    return 0;
}

