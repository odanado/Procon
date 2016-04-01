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
int N;
int Q;
int D[51][51];
int A[55][55];
map<int,int> dp;

int calc(int x0,int y0,int x1,int y1) {
    int ret=0;
    ret = A[x1][y1]-A[x1][y0]-A[x0][y1]+A[x0][y0];
    //printf("clac: %d,%d %d,%d = %d\n",x0,y0,x1,y1,ret);
    return ret;
}

int main() {
    cin>>N;
    rep(i,N) rep(j,N) cin>>D[i][j];
    rep(i,N) rep(j,N) A[i+1][j+1]=D[i][j];
    rep(i,N+1) rep(j,N+1) A[i+1][j]+=A[i][j];
    rep(j,N+1) rep(i,N+1) A[i][j+1]+=A[i][j];

    rep(x0,N) rep(y0,N) rep(x1,N+1) rep(y1,N+1) {
        if(x1-x0<=0 || y1-y0<=0) continue;
        int s=(x1-x0)*(y1-y0);
        if(s==0) continue;
        dp[s]=max(dp[s],calc(x0,y0,x1,y1));
    }
    rep(i,50*50+1) if(i) dp[i]=max(dp[i],dp[i-1]);
    cin>>Q;
    while(Q-->0) {
        int P;
        cin>>P;
        int ans=dp[P];
        cout<<ans<<endl;
    }
    return 0;
}

