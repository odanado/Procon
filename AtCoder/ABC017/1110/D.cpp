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
const ll MOD=1000000007;
int N,M;

int f[1000006];
ll dp[5003];

ll dfs(int a) {
    if(a==N) {
        //printf("%d %d\n",a,b);
        return 1;
    }
    if(dp[a]!=-1) return dp[a];

    int S[5003]={};
    ll ret=0;
    while(a!=N) {
        if(S[f[a]]) {
            //ret+=(dfs(a+1,b))%MOD;
            break;
        }
        else {
            S[f[a]]=1;
            ret+=(dfs(a+1))%MOD;
            ret%=MOD;
            a++;
        }
    }

    return dp[a]=ret;
}

int main() {
    memset(dp,-1,sizeof(dp));
    cin>>N>>M;
    if(N>5000 || M>5000) return 0;
    rep(i,N) cin>>f[i];
    ll ans=dfs(0)%MOD;
    cout<<ans<<endl;
    return 0;
}

