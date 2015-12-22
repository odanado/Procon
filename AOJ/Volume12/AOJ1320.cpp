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
string cties[20];
int G[20][20];

int dist(string s1,string s2) {
    if(s1.find(s2)!=string::npos) return s2.size();
    if(s2.find(s1)!=string::npos) return s1.size();
    int ret=0;
    int m=min(s1.size(),s2.size());
    reverse(all(s1));
    rep(i,m) {
        string t=s1.substr(0,i);
        reverse(all(t));
        if(t==s2.substr(0,i)) ret=i;
    }


    return ret;
}
int dp[1<<16][16];
int dfs(int S,int v) {
    if(S+1==1<<n) return dp[S][v]=0;
    if(dp[S][v]!=-1) return dp[S][v];
    int ret=0;
    rep(u,n) {
        if(G[v][u]==INF) continue;
        if(!(S>>u&1)) ret=max(ret,dfs(S|1<<u,u)+G[v][u]);
    }

    return dp[S][v]=ret;
}
void solve() {
    int sum=0;
    rep(i,n) sum+=cties[i].size();
    rep(i,20) rep(j,20) G[i][j]=INF;
    rep(i,n) rep(j,n) if(i!=j) {
        G[i][j]=dist(cties[i],cties[j]);
        G[j][i]=dist(cties[j],cties[i]);
    }
    int ans=INF;
    rep(v,n) {
        memset(dp,-1,sizeof(dp));
        int t=dfs(1<<v,v);
        //cout<<t<<endl;
        ans=min(ans,sum-t);
    }

    cout<<ans<<endl;
}

int main() {
    cout<<dist("A","ABC")<<endl;
    cout<<dist("ABC","A")<<endl;
    while(cin>>n) {
        if(n==0) break;
        rep(i,n) cin>>cties[i];
        solve();
    }
    return 0;
}

