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
bool chmax(T& a,const T& b) {
    if(a<b) {
        a=b;
        return true;
    }
    return false;
}

int C,D,W,X;
int E[50][50];
int F[50][50];
int dp[35][55][10];


void solve() {
    rep(i,C) rep(j,D) cin>>E[i][j];
    rep(i,C) rep(j,D) cin>>F[i][j];
    rep(i,35) rep(j,55) rep(k,10) dp[i][j][k]=-INF;
    dp[0][0][0]=0;

    rep(d,D) rep(w,W+1) rep(x,X+1) {
        chmax(dp[d+1][w][x],dp[d][w][x]);

        rep(i,C) if(w+F[i][d]<=W && E[i][d]!=0) 
            chmax(dp[d+1][w+F[i][d]][x],dp[d][w][x]+E[i][d]);

        //[i,j]でライブ
        rep(i,C) {
            int sum=0,sumF=0;
            for(int j=i;j<C;j++) {
                sum+=E[j][d];
                sumF+=F[j][d];
                if(E[j][d]==0) break;
                if(j-i==0) continue;
                if(w+sumF<=W&&x+1<=X) {
                    // printf("%d %d %d -> %d %d %d\n",d+1,w+sumF,x+1,d,w,x);
                    chmax(dp[d+1][w+sumF][x+1],dp[d][w][x]+sum);
                }

            }

        }

    }
    int ans=0;
    rep(w,W+1) rep(x,X+1) ans=max(ans,dp[D][w][x]);

    cout<<ans<<endl;

}

int main() {
    while(cin>>C>>D>>W>>X) {
        if(C+D+W+X==0) break;
        solve();
    }
    return 0;
}

