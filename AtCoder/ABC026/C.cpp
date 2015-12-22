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

const int inf=100000000;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
using namespace std;
typedef pair<int ,int > p;
typedef long long ll;

int n;
vector<int> g[30];
ll dfs(int v) {
    if(g[v].size()==0) return 1;
    ll mini=1e15;
    ll maxi=0;
    rep(i,g[v].size()) {
        ll ret=dfs(g[v][i]);
        mini=min(ret,mini);
        maxi=max(ret,maxi);
    }

    return mini+maxi+1;
}
int main() {
    cin>>n;
    rep(i,n-1) {
        int b;
        cin>>b;
        g[b].pb(i+2);
    }
    cout<<dfs(1)<<endl;
    return 0;
}

