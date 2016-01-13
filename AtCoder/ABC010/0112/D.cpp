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

/*
 * 最大流
 * Ford Fulkerson法
 * O(F|E|)
 *
 * http://poj.org/problem?id=3281
 *
 */

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
int N,G,E;
int main() {
    cin>>N>>G>>E;
    FordFulkerson ff(N+1);
    rep(i,G) {
        int p;
        cin>>p;
        ff.add_edge(p,N,1);
    }
    rep(i,E) {
        int a,b;
        cin>>a>>b;
        ff.add_edge(a,b,1);
        ff.add_edge(b,a,1);
    }
    cout<<ff.max_flow(0,N)<<endl;
    return 0;
}

