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
struct Artist {
    int e,s;
    Artist(int e=0,int s=0) :
        e(e),s(s) {}
};
void input(int len, Artist *a) {
    rep(i,len) {
        string ss;
        int e,s;
        cin>>ss>>e>>s;
        a[i]=Artist(e,s);
    }
}
Artist artist1[102], artist2[102];
// インデックス、人数、金額
int dp1[102][5][1003];
int dp2[102][102][1003];

int lim,n,m,x;

void solve() {
    rep(i,102) rep(j,5) rep(k,1003) dp1[i][j][k]=-1;
    rep(i,102) rep(j,102) rep(k,1003) dp2[i][j][k]=-1;

    input(n,artist1);
    input(m,artist2);
    dp1[0][0][0]=dp2[0][0][0]=0;

    rep(k,lim) rep(i,n) rep(j,3) {
        Artist a=artist1[i];
        int lim_n = k+a.e;
        if(lim_n <= lim&&dp1[i][j][k]!=-1) 
            chmax(dp1[i+1][j+1][lim_n],dp1[i][j][k]+a.s);
        chmax(dp1[i+1][j][k],dp1[i][j][k]);
    }
    rep(k,lim) rep(i,m) rep(j,m) {
        Artist a=artist2[i];
        int lim_n = k+a.e;
        if(lim_n <= lim&&dp2[i][j][k]!=-1) 
            chmax(dp2[i+1][j+1][lim_n],dp2[i][j][k]+a.s);
        chmax(dp2[i+1][j][k],dp2[i][j][k]);
    }

    //rep(i,20) printf("%d %d\n",i,dp1[n][2][i]);
    //rep(i,20) printf("%d %d\n",i,dp2[m][2][i]);

    int ans=0;
    rep(i,lim) {
        int max1=max(dp1[n][1][i],dp1[n][2][i]);
        int max2=0;
        for(int j=x;j<=m;j++) for(int k=0;k<=lim-i;k++) chmax(max2,dp2[m][j][k]);

        chmax(ans,max1+max2);
        // printf("%d %d : %d\n",i,lim-i,max1+max2);
    }

    cout<<ans<<endl;
}

int main() {
    while(cin>>lim>>n>>m>>x) {
        if(lim+n+m+x==0) break;
        solve();
    }
    return 0;
}

