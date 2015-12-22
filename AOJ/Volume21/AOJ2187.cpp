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

int gA[10],jA[10];
double dp[1<<9][10][400];

double dfs(int gS,int j,int sum) {
    // printf("%d : %d %d %d\n",__builtin_popcount(gS),gS,jS,sum);
    if(__builtin_popcount(gS) == 9) {
        if(sum>0) return 1.0;
        else return 0.0;
    }
    int p=9-__builtin_popcount(gS);
    if(dp[gS][j][sum+200]!=-1.0) return dp[gS][j][sum+200];
    double ret=0.0;
    rep(i,9) if(!((gS>>i)&1)){
        int a=gA[i]+jA[j];
        int s=sum;
        // printf("%d %d : %d %d\n",gA[i],jA[j],s,a);
        if(gA[i]>jA[j]) s+=a;
        else s-=a;

        ret += dfs(gS|1<<i, j+1, s)*1.0/(p);
    }

    return dp[gS][j][sum+200] = ret;
}

void solve() {
    rep(i,1<<9) rep(j,10) rep(a,400) dp[i][j][a]=-1.0;
    rep(i,9) cin>>gA[i];
    rep(i,9) cin>>jA[i];
    double ans=dfs(0,0,0);
    printf("%.8f %.8f\n",ans,1-ans);
}

int main() {
    int t;
    cin>>t;
    while(t-->0) {
        solve();
    }
    return 0;
}

