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
int A[100005];
int dp[100005];
int main() {
    rep(i,100005) dp[i]=INF;
    cin>>N;
    rep(i,N) cin>>A[i];
    rep(i,N) {
        *lower_bound(dp,dp+N,A[i])=A[i];
    }
    int ans=lower_bound(dp,dp+N,INF)-dp;
    cout<<N-ans<<endl;
    return 0;
}

