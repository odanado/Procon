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

bool visited[100005];
vector<int> G[100005];
int n,m;
ll ans=0;
int edgeCount[100005];
int d[100005];
int main() {
    cin>>n>>m;
    set<int> vs;
    rep(i,m) {
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        if(u>v) swap(u,v);
        edgeCount[u]++;
        edgeCount[v]++;
        G[u].push_back(v);
        vs.insert(u);
        vs.insert(v);
    }
    for(auto v: vs) {
        rep(i,G[v].size()) {
            int u=G[v][i];
            d[u]=max(d[u],d[v]+1);
        }
    }
    for(auto v: vs) {
        //cout<<v<<": "<<d[v]+1<<", "<<edgeCount[v]<<endl;
        ans=max(ans,1LL*(d[v]+1)*edgeCount[v]);
    }

    cout<<ans<<endl;

    return 0;
}
