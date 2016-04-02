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
int N,M;
int t1[200],t2[200],s[200];
int dp[1<<14];

int dfs(int S) {
    if(S+1==(1<<N)) return 0;
    int ret=0;
    if(dp[S]!=-1) return dp[S];
    rep(i,N) if(!(S>>i&1)) {
        int sum=0;
        rep(j,M) {
            if(t2[j]!=i) continue;
            if(S>>t1[j]&1) sum+=s[j];
        }
        ret=max(dfs(S|1<<i)+sum,ret);
    }
    return dp[S]=ret;
}

int main() {
    memset(dp,-1,sizeof(dp));
    cin>>N>>M;
    rep(i,M) cin>>t1[i]>>t2[i]>>s[i];
    cout<<dfs(0)<<endl;
    return 0;
}

