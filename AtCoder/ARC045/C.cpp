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

struct Edge {
    ll to,cost;
};
int N,X;
vector<Edge> G[100005];
// 0からのxor和
ll s[100005];
ll a[100005];

void dfs(int v,int u,ll x) {
    s[v]=x;
    rep(i,G[v].size()) {
        Edge e=G[v][i];
        if(u==e.to) continue;
        dfs(e.to,v,x^e.cost);
    }
}

int main() {
    int v=0;
    cin>>N>>X;
    rep(i,N-1) {
        ll a,b,c;
        cin>>a>>b>>c;
        a--;
        b--;
        G[a].push_back(Edge{b,c});
        G[b].push_back(Edge{a,c});
    }
    rep(i,N) if(G[i].size()==1) v=i;
    dfs(v,-1,0);
    rep(i,N) a[i]=s[i];
    sort(a,a+N);
    ll ans=0;
    rep(i,N) {
        ll x=X^s[i];
        ll t1=upper_bound(a,a+N,x)-a;
        ll t2=lower_bound(a,a+N,x)-a;
        ans+=t1-t2;
        if(x==s[i]) {
            ans-=1;
        }
    }
    ans>>=1;
    cout<<ans<<endl;

    return 0;
}

