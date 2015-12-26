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
int W[102];
int dp[102][10004];
int dfs(int idx,int s,int m) {
    if(s==m) return true;
    if(idx==N) return false;
    if(s>m) return false;
    if(dp[idx][s]!=-1) return dp[idx][s];
    bool ret = false;
    ret |= dfs(idx+1,s,m);
    ret |= dfs(idx+1,s+W[idx],m);

    return dp[idx][s]=ret;
}
int main() {
    cin>>N;
    rep(i,N) cin>>W[i];
    int s = 0;
    rep(i,N) s+=W[i];
    if(s%2==1) {
        cout<<"impossible"<<endl;
        return 0;
    }
    memset(dp,-1,sizeof(dp));
    int m = s/2;
    if(dfs(0,0,m)) {
        cout<<"possible"<<endl;
    }
    else {
        cout<<"impossible"<<endl;
    }
    return 0;
}

