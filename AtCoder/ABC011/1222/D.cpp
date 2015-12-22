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
#include <tuple>

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

ll N,D;
ll X,Y;
double dp[64][64][31];
double dfs(ll x, ll y,int cnt) {
    if(cnt==0) {
        if(x==X&&y==Y) return 1;
        else return 0;
    }
    if(dp[x+32][y+32][cnt]!=-1) return dp[x+32][y+32][cnt];
    double ret=0;

    ret += dfs(x+D,y,cnt-1)/4.0;
    ret += dfs(x-D,y,cnt-1)/4.0;
    ret += dfs(x,y+D,cnt-1)/4.0;
    ret += dfs(x,y-D,cnt-1)/4.0;
    return dp[x+32][y+32][cnt]=ret;
}

ll C[31][31];

void init() {
    rep(i,31) C[i][0]=1;
    rep(i,30) rep(j,30)
        C[i+1][j+1]=C[i][j+1]+C[i][j];
}


int main() {
    rep(i,64) rep(j,64) rep(k,31) dp[i][j][k]=-1;
    init();
    cin>>N>>D;
    cin>>X>>Y;
    if(N>30) return 0;
    if(X%D!=0||Y%D!=0) {
        printf("%.20f\n",0.0);
        return 0;
    }
    X=X/D;
    Y=Y/D;
    D=1;

    printf("%.20f\n",dfs(0,0,N));
    return 0;
}

