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

struct FordFulkerson{
    struct Edge { 
        int to,cap,rev; 
        Edge(int to=0,int cap=0,int rev=0) :
            to(to),cap(cap),rev(rev){}
    };

    int V;
    vector<vector<Edge> > G;
    vector<bool> used;

    FordFulkerson(int V) : V(V) {
        G.resize(V);
        used.assign(V,false);
    }

    void add_edge(int from,int to,int cap) {
        G[from].pb(Edge(to,cap,G[to].size()));
        G[to].pb(Edge(from,0,G[from].size()-1));
    }

    int dfs(int v,int t,int f) {
        if(v==t) return f;
        used[v]=true;
        for(int i=0;i<G[v].size();i++) {
            Edge &e=G[v][i];

            if(!used[e.to] && e.cap>0) {
                int d=dfs(e.to,t,min(f,e.cap));
                if(d>0) {
                    e.cap-=d;
                    G[e.to][e.rev].cap+=d;
                    return d;
                }
            }
        }
        return 0;
    }

    int max_flow(int s,int t) {
        int flow=0;
        while(1) {
            used.assign(V,false);
            int f=dfs(s,t,INF);
            if(f==0) break;
            flow+=f;
        }

        return flow;
    }

};

int N,F,D;
bool likeF[102][102];
bool likeD[102][102];

int main() {
    scanf("%d %d %d",&N,&F,&D);
    rep(i,N) {
        int a,b;
        int x;
        scanf("%d %d",&a,&b);
        rep(j,a) {
            cin>>x;
            x--;
            likeF[i][x]=true;
        }
        rep(j,b) {
            cin>>x;
            x--;
            likeD[i][x]=true;
        }
    }
    int s=N*2+F+D;
    int t=s+1;

    FordFulkerson ff(t+1);
    
    rep(i,F) ff.add_edge(s,N*2+i,1);
    rep(i,D) ff.add_edge(N*2+F+i,t,1);

    rep(i,N) {
        ff.add_edge(i,N+i,1);
        rep(j,F) if(likeF[i][j]) ff.add_edge(N*2+j,i,1);
        rep(j,D) if(likeD[i][j]) ff.add_edge(N+i,N*2+F+j,1);
    }

    printf("%d\n",ff.max_flow(s,t));

    return 0;
}

