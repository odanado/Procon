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
int W,H;
int S,T;
int grid[102][102];
int f(int y,int x) {
    int ret = 0;
    for(int i=y;i<y+T;i++) {
        if(!(0<=i&&i<H)) continue;
        for(int j=x;j<x+S;j++) {
            if(!(0<=j&&j<W)) continue;
            if(grid[i][j]) ret++;
        }
    }
    return ret;
}
void solve() {
    rep(i,102) rep(j,102) grid[i][j]=0;
    cin>>W>>H;
    rep(i,N) {
        int x,y;
        cin>>x>>y;
        x--; y--;
        grid[y][x]=1;
    }
    cin>>S>>T;
    int ans = 0;
    rep(i,H) rep(j,W) {
        ans=max(ans,f(i,j));
    }
    cout<<ans<<endl;

}
int main() {
    while(cin>>N) {
        if(N==0) return 0;
        solve();
    }
    return 0;
}

