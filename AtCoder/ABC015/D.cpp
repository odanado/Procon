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

template<class T>
bool chmax(T &a, const T &b) {
    if(a<b) {
        a=b;
        return true;
    }
    return false;
}
int W;
int N,K;
int A[51],B[51];
// i番目まででj枚貼り付けて、幅がk
int dp[55][55][10004];
int main() {
    cin>>W>>N>>K;
    rep(i,N) cin>>A[i]>>B[i];
    rep(i,N) rep(j,K+1) rep(k,W+1) {
        chmax(dp[i+1][j][k],dp[i][j][k]);
        if(k+A[i]>W) continue;
        if(j+1>K) continue;
        chmax(dp[i+1][j+1][k+A[i]],dp[i][j][k]+B[i]);
    }
    int ans=0;
    rep(i,K+1) {
        rep(j,W+1) {
            //printf("%d %d: %d\n",i,j,dp[N][i][j]);
            chmax(ans,dp[N][i][j]);
        }
        //cout<<endl;
    }
    cout<<ans<<endl;
    return 0;
}

