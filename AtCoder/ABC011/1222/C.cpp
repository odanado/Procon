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
int ng[3];
int dp[302][102];
bool ok(int n) {
    rep(i,3) if(n==ng[i]) return false;
    return true;
}

bool dfs(int n,int cnt) {
    if(cnt>100) return false;
    if(!ok(n)) return false;
    if(n==0) return true;
    if(n<0) return false;
    if(dp[n][cnt]!=-1) return dp[n][cnt];
    bool ret = false;
    ret |= dfs(n-1,cnt+1);
    ret |= dfs(n-2,cnt+1);
    ret |= dfs(n-3,cnt+1);

    return dp[n][cnt]=ret;
}
int main() {
    memset(dp,-1,sizeof(dp));
    cin>>N;
    rep(i,3) cin>>ng[i];
    if(dfs(N,0)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}

