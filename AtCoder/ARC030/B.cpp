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

int n,x;
int h[102];
vector<int> G[102];
int ans;

bool dfs(int v, int u) {
    bool flag = h[v];

    rep(i,G[v].size()) {
        int e = G[v][i];
        if(u==e) continue;
        bool tmp = dfs(e,v);
        if(tmp) ans+=2;
        flag |= tmp;
    }


    return flag;
}

int main() {
    cin>>n>>x;
    x--;
    rep(i,n) cin>>h[i];
    rep(i,n-1) {
        int a,b;
        cin>>a>>b;
        a--,b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    dfs(x,-1);
    cout<<ans<<endl;
    return 0;
}

