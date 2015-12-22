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
typedef pair<int ,double > P;
typedef long long ll;

map<string,int> ids;
int to_id(string &s) {
    if(!ids.count(s)) ids[s]=ids.size();

    return ids[s];
}

struct Edge {
    int to;
    double cost;
};

vector<Edge> G[1000];
double dist[1000][1000];

double bfs(int s) {
    bool f[1000]={};
    int ret=0;
    queue<P> que;
    que.push(P(s,1));
    dist[s][s]=1;

    while(que.size()) {
        P p=que.front(); que.pop();
        int v=p.fr;
        int cost=p.sc;
        rep(i,G[v].size()) {
            Edge e=G[v][i];
            if(dist[s][e.to]<dist[s][v]*e.cost) {
                dist[s][e.to]=dist[s][v]*e.cost;
                que.push(P(e.to,dist[s][e.to]));
            }
        }
    }


    return *max_element(dist[s],dist[s]+1000);
}

string to_s(int id) {
    for(auto &e : ids) {
        if(e.sc==id) return e.fr;
    }
    return "";
}

int main() {
    int n;
    cin>>n;
    rep(i,n) {
        string s1,s2;
        double m;
        cin>>s1>>m>>s2;
        G[to_id(s1)].push_back({to_id(s2),m});
        G[to_id(s2)].push_back({to_id(s1),1.0/m});
    }
    double ans=0;
    for(auto &id : ids) {
        ans=max(ans,bfs(id.sc));
    }

    for(auto &id1 : ids) {
        for(auto &id2 : ids) {
            if(dist[id1.sc][id2.sc]==ans&&id1.fr!=id2.fr) {
                cout<<"1"<<id1.fr<<"="<<ans<<id2.fr<<endl;
                return 0;
            }
        }
    }
    
    return 0;
}

