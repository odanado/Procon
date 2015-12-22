#include<algorithm>
#include<functional>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<climits>

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define FOR(itr,data) for(__typeof((data).begin()) itr=(data).begin();itr!=(data).end();++itr)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

typedef unsigned long long UInt64;
typedef long long Int64;

const int INF=100000000;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

using namespace std;

typedef pair<int ,int > P;

int n;
struct edge {
    int to,cost;
    edge(int to,int cost) {
        this->to = to;
        this->cost = cost;
    }
};
vector<edge> G[100007];
int d[100007];

//頂点 sからの最遠点
int bfs(int s) {
    rep(i,100007) d[i]=INF;
    d[s]=0;

    queue<P> que;
    que.push(P(0,s));
    
    while(que.size()) {
        P p = que.front(); que.pop();
        //printf("[debug] %d %d\n",p.fr,p.sc);

        rep(i,G[p.sc].size()) {
            edge e = G[p.sc][i];
            if(d[e.to] > d[p.sc]+e.cost) {
                d[e.to] = d[p.sc]+e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
    int maxi=0,v;
    rep(i,n) {
        if(maxi<d[i]&&d[i]!=INF) {
            maxi=d[i];
            v=i;
        }
    }

    return v;
} 

int main() {
    cin>>n;
    int a,b;
    rep(i,n-1) {
        cin>>a>>b;
        a--;b--;
        G[a].pb(edge(b,1));
        G[b].pb(edge(a,1));
    }
    int v,u;
    v = bfs(a);
    u = bfs(v);
    v++;u++;
    cout<<v<<" "<<u<<endl;
    return 0;
}




/* 2014/05/03 AC */

