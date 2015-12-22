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
int s[1<<16+1];
int d[1<<16+1];

vector<P> ans;

void dfs(int u) {
    if(d[u]==0) return;
    int v = s[u];
    d[v]--;
    d[u]--;
    s[v]^=u;
    s[u]^=v;

    ans.pb(P(u,v));

    if(d[v]==1) dfs(v);

}

int main() {
    cin>>n;
    rep(i,n) cin>>d[i]>>s[i];

    rep(i,n) {
        if(d[i]==1) {
            dfs(i);
        }
    }
    cout<<ans.size()<<endl;
    for(auto e : ans) {
        cout<<e.fr<<" "<<e.sc<<endl;
    }


    return 0;
}

