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

int T;
int t[102];
int N;
int D[102],M[102];
int max_d;

map<int,int> jobs;
int dp[102][102];

// a日目にb番目のサイクル
int dfs(int a,int b) {
    //printf("%d %d\n",a,b);
    if(a==max_d+1) return 0;
    if(dp[a][b]!=-1) return dp[a][b];

    int ret=INF;
    if(t[(b+1)%T]<=jobs[a+1]) ret=min(ret,dfs(a+1,(b+1)%T));
    ret=min(ret,dfs(a+1,0)+1);

    return dp[a][b]=ret;
}

void solve() {
    jobs.clear();
    max_d=0;
    rep(i,N) {
        max_d=max(max_d,D[i]);
    }
    rep(i,max_d+1) jobs[i]=INF;
    rep(i,N) {
        jobs[D[i]]=min(jobs[D[i]],M[i]);
    }
    memset(dp,-1,sizeof(dp));
    cout<<dfs(1,0)-1<<endl;
}

int main() {
    while(cin>>T) {
        if(!T) break;
        rep(i,T) cin>>t[i];
        cin>>N;
        rep(i,N) cin>>D[i]>>M[i];
        solve();
    }
    return 0;
}

