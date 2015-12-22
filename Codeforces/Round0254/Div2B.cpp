#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
int n,m;
vector<int> G[52];
const int MAX_N = 52;
int par[MAX_N];
int rank[MAX_N];
void init(int n) {
    rep(i,n) {
        par[i]=i;
        rank[i]=0;
    }
}
int find(int x) {
    if(par[x]==x) return x;
    else return par[x]=find(par[x]);
}
void unit(int x,int y) {
    x = find(x);
    y = find(y);
    if(x==y) return;
    if(rank[x]<rank[y]) {
        par[x]=y;
    }
    else {
        par[y]=x;
        if(rank[x]==rank[y]) rank[x]++;
    }
}
bool same(int x,int y) {
    return find(x)==find(y);
}
int main() {
    cin>>n>>m;
    long long ans = 1;
    init(n+1);
    rep(i,m) {
        int a,b;
        cin>>a>>b;
        if(!same(a,b)) {
            unit(a,b);
            ans *= 2;
        }
    }
    cout<<ans<<endl;

    return 0;
}
