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

int n;
ll x,y;
ll ans;
vector<int> G[200005];
int dfs1(int v,int u) {
    int a=2;
    for(int nxt:G[v]) {
        if(nxt==u) continue;
        int x=dfs1(nxt,v);
        if(a>0&&x==1) {
            ans++;
            a--;
        }
    }
    return a>0;
}
void solve1() {
    int v=0;
    dfs1(v,-1);
    ans=(n-1-ans)*y+ans*x;
}
// (v,d)
P dfs2(int v,int u) {
    P ret=P(v,0);
    for(auto nxt:G[v]) {
        if(u==nxt) continue;
        P p=dfs2(nxt,v);
        p.sc+=1;
        if(p.sc>ret.sc) ret=p;
    }

    return ret;
}
void solve2() {
    auto p=dfs2(0,-1);
    p=dfs2(p.fr,-1);
    if(p.sc==1||p.sc==2) {
        ans=(n-2)*y+x;
    }
    else {
        ans=(n-1)*y;
    }
}
int main() {
    cin>>n>>x>>y;
    rep(i,n-1) {
        int a,b;
        cin>>a>>b;
        a--,b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    if(x<y) solve1();
    else solve2();
    cout<<ans<<endl;
    return 0;
}

