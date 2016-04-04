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
int W,H;
int N;
int X[31],Y[31];
map<tuple<int,int,int,int>,ll> dp;

ll dfs(int x1,int y1,int x2,int y2) {
    ll ret=0;
    //printf("%d %d %d %d\n",x1,y1,x2,y2);
    auto tmp=tie(x1,y1,x2,y2);
    if(dp.count(tmp)) return dp[tmp];
    rep(i,N) {
        if(!(x1<=X[i]&&X[i]<=x2)) continue;
        if(!(y1<=Y[i]&&Y[i]<=y2)) continue;
        ll t=x2-x1+y2-y1+1;
        t+=dfs(x1,y1,X[i]-1,Y[i]-1);
        t+=dfs(x1,Y[i]+1,X[i]-1,y2);
        t+=dfs(X[i]+1,Y[i]+1,x2,y2);
        t+=dfs(X[i]+1,y1,x2,Y[i]-1);
        ret=max(ret,t);
    }

    //printf("%d %d %d %d %d: %lld\n",i,x1,y1,x2,y2,ret);
    return dp[tmp]=ret;
}

int main() {
    cin>>W>>H;
    cin>>N;
    rep(i,N) cin>>X[i]>>Y[i];
    cout<<dfs(1,1,W,H)<<endl;
    return 0;
}

