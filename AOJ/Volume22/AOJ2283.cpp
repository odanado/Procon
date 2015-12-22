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
bool chmin(T& a,const T& b) {
    if(b<a) {
        a=b;
        return true;
    }

    return false;
}

struct Edge {
    int to,cost;
    Edge(int to,int cost) : 
        to(to),cost(cost) {}
};
vector<Edge> G[502];

int n,m;
map<string,int> ids;

int to_id(string s) {
    if(!ids.count(s)) ids[s]=ids.size();

    return ids[s];
}
int dijk(int s,int t) {
    int d[502];
    rep(i,502) d[i]=INF;
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
void solve() {
    rep(i,502) G[i].clear();
    ids.clear();
    string s,p,g;
    cin>>s>>p>>g;
    to_id(s);
    to_id(p);
    to_id(g);
    rep(i,m) {
        string a,b;
        int c,d;
        cin>>a>>b>>c>>d;
        G[to_id(a)].pb(Edge(to_id(b),c/40+d));
        G[to_id(b)].pb(Edge(to_id(a),c/40+d));
    }

    int ans=dijk(to_id(s),to_id(p));
    ans+=dijk(to_id(p),to_id(g));
    cout<<ans<<endl;

}

int main() {
    while(cin>>n>>m) {
        if(n+m==0) break;
        solve();
    }
    return 0;
}

