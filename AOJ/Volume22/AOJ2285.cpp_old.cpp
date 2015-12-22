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

int lim,n,m,x;
map<string, int> ids;
int to_id(string s) {
    if(!ids.count(s)) ids[s]=ids.size();
    return ids[s];
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

template<class T>
int get_max(T a,int c,int len,int s,int t) {
    int ret=0;
    for(int j=s;j<=t;j++) {
        chmax(ret,a[c][len][j]);
    }

    return ret;
}

Artist artist1[102], artist2[102];
// 金額、インデックス、人数
int dp1[1003][102][5];
int dp2[1003][102][102];


void solve() {
    ids.clear();
    rep(i,1003) rep(j,102) {
        rep(k,5) dp1[i][j][k]=0;
        rep(k,102) dp2[i][j][k]=0;
    }

    input(n,artist1);
    input(m,artist2);

    rep(j,n) rep(i,lim) rep(k,3) {
        int lim_n = i+artist1[j].e;
        if(lim_n > lim) continue;
        chmax(dp1[lim_n][j+1][k+1],dp1[i][j][k]+artist1[j].s);
    }

    rep(j,m) rep(i,lim) rep(k,m+1) {
        int lim_n = i+artist2[j].e;
        if(lim_n > lim) continue;
        chmax(dp2[lim_n][j+1][k+1],dp2[i][j][k]+artist2[j].s);
    }

    // rep(i,15) printf("%d %d\n",i,dp2[i][m-1][m]);
    // rep(i,27) printf("%d %d\n",i,dp1[i][n-1][2]);

    int ans=0;
    rep(i,lim) {
        int t=get_max(dp2,i,m-1,x,m);
        chmax(ans,t+get_max(dp1,lim-i,n-1,1,2));
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

