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
int n,x;
int d[20],c[20];
int dp[200010];
int main() {
    rep(i,200010) dp[i]=INF;
    dp[0]=0;
    cin>>n>>x;
    rep(i,n) cin>>d[i]>>c[i];
    rep(i,n) rep(pos,200010) {
        int t=pos+d[i];
        if(t<200010) dp[t]=min(dp[t],dp[pos]+c[i]);
    }
    int ans=dp[x];
    rep(i,200010) {
        if(!i) continue;
        int pos=x+i;
        int diff=pos-x;
        ans=min(ans,dp[pos]+dp[diff]);
    }
    if(ans==INF) ans=-1;
    cout<<ans<<endl;

    return 0;
}

