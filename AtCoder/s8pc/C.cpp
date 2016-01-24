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
typedef long long ll;
typedef pair<ll ,int > P;

int N,K;
ll D[51];
vector<int> G[51];

ll dfs(ll S,int v) {
    ll ret=0;
    rep(i,G[v].size()) {
        int u=G[v][i];
        if(S>>u&1) continue;
        ret=max(ret,dfs(S|1LL<<u,u)+D[u]);
    }

    return ret;
}
int main() {
    cin>>N>>K;
    set<int> vs;
    rep(i,N) cin>>D[i];
    rep(i,K) {
        int a,b;
        cin>>a>>b;
        a--,b--;
        G[a].pb(b);
        G[b].pb(a);
        vs.insert(a);
        vs.insert(b);
    }

    ll ans=0;
    for(auto v:vs) {
        ans=max(ans,dfs(1LL<<v,v)+D[v]);
        //cout<<v<<", "<<ans<<endl;
    }
    cout<<ans<<endl;
    return 0;
}

