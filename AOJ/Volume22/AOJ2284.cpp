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

const int MAX_V = 20000;
int w,h;
struct Edge {
    int to,cost;
    Edge(int to,int cost) : 
        to(to),cost(cost) {}
};
map<pair<P,string>,int> ids;
vector<Edge> G[MAX_V];
template<class T>
bool chmin(T& a,const T& b) {
    if(b<a) {
        a=b;
        return true;
    }

    return false;
}
int to_id(P p,string s) {
    pair<P,string> ps=pair<P,string>(p,s);
    if(!ids.count(ps)) ids[ps]=ids.size();

    return ids[ps];
}
int d[MAX_V];
int dijk(int s,int t) {
    rep(i,MAX_V) d[i]=INF;
    d[s]=0;
    priority_queue<P,vector<P>,greater<P> > que;
    que.push(P(0,s));

    while(que.size()) {
        P p=que.top(); que.pop();
        int v=p.sc;
        int cost=p.fr;

        rep(i,G[v].size()) {
            Edge e=G[v][i];
            if(chmin(d[e.to],d[v]+e.cost)) {
                que.push(P(d[e.to],e.to));
            }
        }
    }

    return d[t];
}


int diff(P p1,P p2) {
    return abs(p1.fr-p2.fr)+abs(p1.sc-p2.sc);
}
string to_s(int n) {
    stringstream ss;
    ss<<n;
    return ss.str();
}
int to_i(string& s) {
    int ret;
    stringstream ss;
    ss<<s;
    ss>>ret;
    return ret;
}
string maze[102][102];
void solve() {
    rep(i,MAX_V) G[i].clear();
    rep(i,h) rep(j,w) cin>>maze[i][j];
    map<string,set<P> > points;
    vector<int> vec;
    rep(y,h) rep(x,w) {
        if(maze[y][x]!=".") points[maze[y][x]].insert(P(y,x));
        if(maze[y][x]!="."&&maze[y][x]!="S"&&maze[y][x]!="G") vec.pb(to_i(maze[y][x]));
    }
    sort(all(vec));
    vec.erase(unique(all(vec)),vec.end());

    /*
    to_id("S");
    rep(i,vec.size()) to_id(to_s(vec[i]));
    to_id("G");
    // */

    rep(i,vec.size()+1) {
        string s=to_s(i);
        string t=to_s(i+1);
        if(i==0) s="S";
        if(i==vec.size()) t="G";
        for(auto& e1 : points[s]) {
            for(auto& e2 : points[t]) {
                // cout<<s<<" -> "<<t<<" : "<<diff(e1,e2)<<endl;
                G[to_id(e1,s)].pb(Edge(to_id(e2,t),diff(e1,e2)));
            }
        }
    }

    return;

    cout<<dijk(to_id(*points["S"].begin(),"S"),to_id(*points["G"].begin(),"G"))<<endl;
}

int main() {
    while(cin>>w>>h) {
        if(w+h==0) break;
        solve();
    }
    return 0;
}

