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

vector<int> G[100005];
int N;
int ans[100005];
int dfs(int v, int u) {
    int cnt=1;
    for(int i=0;i<G[v].size();i++) {
        int e = G[v][i];
        if(e == u) continue;
        int t = dfs(e,v);
        cnt += t;
        ans[v] = max(ans[v],t);
    }
    ans[v] = max(ans[v],N-cnt);
    return cnt;
}
int main() {
    cin>>N;
    rep(i,N-1) {
        int p;
        cin>>p;
        G[i+1].pb(p);
        G[p].pb(i+1);
    }
    dfs(0,-1);
    rep(i,N) {
        cout<<ans[i]<<endl;
    }
    return 0;
}

