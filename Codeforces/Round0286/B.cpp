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

struct edge {
    int to;
    int color;
    edge(int to=0,int color=0) : to(to), color(color) {}
};
vector<edge> G[107];
int n,m;

bool ok(int v,int u, int color) {
    bool flag[107]={};

    queue<int> que;
    que.push(v);
    while(que.size()) {
        int a = que.front();
        que.pop();
        if(a==u) return true;
        if(flag[a]) continue;
        flag[a]=true;
        rep(i,G[a].size()) {
            edge e = G[a][i];
            if(e.color != color) continue;
            que.push(e.to);
        }

    }

    return false;

}
int main() {
    int color_max=0;

    cin>>n>>m;
    rep(i,m) {
        int a,b,c;
        cin>>a>>b>>c;
        a--,b--,c--;
        color_max= max(color_max,c);
        G[a].pb(edge(b,c));
        G[b].pb(edge(a,c));
    }
    int q;
    cin>>q;
    rep(i,q) {
        int v,u;
        cin>>v>>u;
        v--,u--;
        int ans=0;
        rep(i,color_max+1) {
            if(ok(v,u,i)) ans++;
            
        }
        cout<<ans<<endl;

    }
    return 0;
}

