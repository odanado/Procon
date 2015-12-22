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
bool chmin(T &a, const T &b) {
    if(a>b) {
        a=b;
        return true;
    }

    return false;
}

int n,m,s,g1,g2;
int d[102][102];
void solve() {
    s--;
    g1--;
    g2--;
    rep(i,102) rep(j,102) d[i][j]=INF;
    rep(i,102) d[i][i]=0;
    rep(i,m) {
        int a,b,c;
        cin>>a>>b>>c;
        a--;
        b--;
        d[a][b]=c;
    }
    rep(k,n) rep(i,n) rep(j,n) {
        chmin(d[i][j],d[i][k]+d[k][j]);
    }
    int ans=INF;
    rep(v,n) {
        int t=d[s][v];
        t+=d[v][g1]+d[v][g2];
        chmin(ans,t);
    }
    cout<<ans<<endl;
}
int main() {
    while(cin>>n>>m>>s>>g1>>g2) {
        if(!n) break;
        solve();
    }
    return 0;
}

