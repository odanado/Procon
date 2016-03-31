#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
using ll = long long;

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

const ll INF=1e9;
const ll MOD=1e9+7;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int n,m;
vector<int> adj[100005];
bool used[100005];
int ans=0;
vector<int> vs;
void dfs(int v) {
    vs.push_back(v);
    for(auto u:adj[v]) {
        if(used[u]) continue;
        used[u]=true;
        dfs(u);
    }
}
int main() {
    cin>>n>>m;
    rep(i,m) {
        int x,y;
        cin>>x>>y;
        x--,y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    rep(i,n) if(!used[i]) {
        used[i]=true;
        int v_cnt=0;
        int e_cnt=0;
        dfs(i);
        for(auto v:vs) e_cnt+=adj[v].size();
        v_cnt=vs.size();
        e_cnt/=2;
        //cout<<i<<": "<<v_cnt<<", "<<e_cnt<<endl;
        if(e_cnt+1==v_cnt) ans++;
        vs.clear();
    }
    cout<<ans<<endl;
    return 0;
}

