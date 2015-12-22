#include<algorithm>
#include<functional>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<climits>

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define FOR(itr,data) for(__typeof((data).begin()) itr=(data).begin();itr!=(data).end();++itr)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

typedef unsigned long long UInt64;
typedef long long Int64;

const int INF=100000000;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

using namespace std;

typedef pair<int ,int > P;

int dp[1<<12][12][30];
int n,m,k;
int d[107];
int MOD=1000000007;
int bincnt(int S) {
    int res=0;
    rep(i,n) if((S>>i)&1) res++;
    return res;
}

int dfs(int S,int v,int sum) {
    int res=0;
    if(dp[S][v][sum]!=-1) return dp[S][v][sum];
    if(bincnt(S) == k) {
        if(sum==0) return dp[S][v][sum]=1;
        else return dp[S][v][sum]=0;
    }
    rep(i,n) {
        if((S>>i)&1) continue;
        res+=dfs(S|(1<<i),i,(sum+abs(d[v]-d[i]))%m)%MOD;
    }

    return dp[S][v][sum]=res%MOD;

}

int main() {
    memset(dp,-1,sizeof(dp));
    cin>>n>>m>>k;
    if(n>=13) return 0;
    rep(i,n) {
        if(!i) continue;
        int a;cin>>a;
        d[i]+=d[i-1]+a;
    }
    int ans=0;
    rep(i,n) {
        ans+=dfs(1<<i,i,0)%1000000007;
    }
    cout<<ans<<endl;
    return 0;
}



