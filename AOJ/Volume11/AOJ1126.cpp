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

int W,H;

bool flag[70][70][70];
string dp[70][70][70];
string mat[70];

string max_str(const string& s1, const string& s2) {
    if(s1.size() == s2.size()) {
        return s1 > s2?s1:s2;
    }
    else return s1.size() > s2.size() ? s1 : s2;
}
string dfs(int y, int x,int c) {
    if(flag[y][x][c]) return dp[y][x][c];
    string res="";

    rep(i,2) {
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(!(0<=ny&&ny<H)) continue;
        if(!(0<=nx&&nx<W)) continue;
        if(!('0'<=mat[ny][nx]&&mat[ny][nx]<='9')) continue;
        res=max_str(res,mat[ny][nx]+dfs(ny,nx,c+1));

    }

    flag[y][x][c]=true;
    return dp[y][x][c]=res;
}

void solve() {
    rep(i,70) {
        mat[i]="";
        rep(j,70) rep(a,70) {
            dp[i][j][a]="";
            flag[i][j][a]=false;
        }
    }

    rep(i,H) cin>>mat[i];

    string ans="";

    rep(i,H) rep(j,W) if('1'<=mat[i][j]&&mat[i][j]<='9') {
        string s="a";
        s[0]=mat[i][j];
        ans=max_str(ans,s+dfs(i,j,0));
    }

    cout<<ans<<endl;
}

int main() {
    while(cin>>W>>H) {
        if(W+H==0) break;
        solve();

    }
    return 0;
}

