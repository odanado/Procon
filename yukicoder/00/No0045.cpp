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
int V[1003];
int dp[1003][2];
int dfs(int idx,int ok) {
    if(idx==N) return 0;
    int ret=0;
    if(dp[idx][ok]!=-1) return dp[idx][ok];
    ret = max(ret,dfs(idx+1,1));
    if(ok) ret = max(ret,dfs(idx+1,0)+V[idx]);
    return dp[idx][ok]=ret;
}
int main() {
    memset(dp,-1,sizeof(dp));
    cin>>N;
    rep(i,N) cin>>V[i];
    cout<<dfs(0,1)<<endl;
    return 0;
}

