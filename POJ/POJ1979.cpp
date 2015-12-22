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
char grid[30][30];
int dfs(int y,int x) {
    //cout<<y<<","<<x<<endl;
    grid[y][x]='#';
    int ret = 0;
    rep(i,4) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(!(0<=nx&&nx<W)) continue;
        if(!(0<=ny&&ny<H)) continue;
        if(grid[ny][nx]!='.') continue;
        ret += dfs(ny,nx)+1;
    }
    return ret;
}
void solve() {
    rep(i,30) rep(j,30) grid[i][j]='#';
    rep(i,H) rep(j,W) cin>>grid[i][j];

    int ans = 0;
    rep(i,H) rep(j,W) if(grid[i][j]=='@') ans = dfs(i,j);
    cout<<ans+1<<endl;

    
}
int main() {
    while(cin>>W>>H) {
        if(W+H==0) return 0;
        solve();
    }
    return 0;
}

