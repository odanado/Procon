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

int N;
int L[102];
int mask[102];
ll dp[102][1<<16];

ll dfs(int a,int b) {
    if(a==N) return 0;
    if(dp[a][b]!=-1) return dp[a][b];

    ll res=0;
    res=max(res,dfs(a+1,b));
    if((b&mask[a])==0)
        res=max(res,dfs(a+1,b|mask[a])+L[a]);

    return dp[a][b]=res;
}

void solve() {
    rep(i,102) mask[i]=0;
    memset(dp,-1,sizeof(dp));
    rep(i,N) {
        int m;
        cin>>m>>L[i];
        rep(j,m) {
            int s,e;
            cin>>s>>e;
            s-=6;
            e-=6;
            for(int k=s;k<e;k++) mask[i] |= 1<<k;
        }
    }
    cout<<dfs(0,0)<<endl;


}

int main() {
    while(cin>>N) {
        if(!N) break;
        solve();
    }
    return 0;
}

