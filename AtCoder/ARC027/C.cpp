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
int X,Y;
int N;
int t[302];
int h[302];
map<double,P> data;
int dp[302][302][302];

int dfs(int i_,int x_,int y_) {
    if(i_==N) return 0;
    //cout<<x_<<","<<y_<<endl;
    if(dp[i_][x_][y_]!=-1) return dp[i_][x_][y_];
    int ret=0;

    for(int i=i_;i<N;i++) {
        for(int j=1;j<=x_;j++) {
            if(t[i]-j<0) continue;
            if(x_-j<0) continue;
            if(y_-(t[i]-j)<0) continue;
            ret = max(ret,dfs(i+1,x_-j,y_-(t[i]-j))+h[i]);
        }
    }
    return dp[i_][x_][y_] = ret;
}

int main() {
    rep(i,302) rep(k,302) rep(j,302) dp[i][k][j]=-1;
    cin>>X>>Y;
    cin>>N;
    rep(i,N) cin>>t[i]>>h[i];
    
    cout<<dfs(0,X,Y)<<endl;
    return 0;
}

// 30 points

