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
typedef pair<int ,P > Pi;
typedef long long ll;
const int MOD=1e9+7;

int N,a,b;
int M;
int dist[102][102];
bool visit[102];
int dp[102][1003];
vector<int> G[102];
int main() {
    rep(i,102) rep(j,102) dist[i][j]=INF;
    rep(i,102) dist[i][i]=0;
    cin>>N>>a>>b;
    a--,b--;
    cin>>M;
    rep(i,M) {
        int x,y;
        cin>>x>>y;
        x--,y--;
        dist[x][y]=1;
        dist[y][x]=1;
        G[x].pb(y);
        G[y].pb(x);
    }


    rep(k,102) rep(i,102) rep(j,102) dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);


    queue<P> que;
    que.push(P(a,0));
    dp[a][0]=1;
    visit[a]=true;
    while(que.size()) {
        P p=que.front();que.pop();
        int v=p.fr;
        int cost=p.sc;
        rep(i,G[v].size()) {
            int u=G[v][i];
            if(dist[a][v]>dist[a][u]) continue;
            //printf("[debug] %d %d -> %d %d\n",v,cost,u,cost+1);
            dp[u][cost+1]=(dp[u][cost+1]+dp[v][cost])%MOD;
            if(visit[u]) continue;
            visit[u]=true;
            que.push(P(u,cost+1));
        }
    }


    cout<<dp[b][dist[a][b]]<<endl;


    return 0;
}

