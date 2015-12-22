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
int H,W;
vector<string> data;

bool dfs(int y,int x, int d,char c) {
    int ny=y+dy[d];
    int nx=x+dx[d];
    if(!(0<=nx&&nx<W)) return true;
    if(!(0<=ny&&ny<H)) return true;
    if(data[ny][nx]=='.') {
        if(data[y+dx[d]][x+dy[d]]!='c') return false;
    }
    else if(data[ny][nx]==c) return dfs(ny,nx,d,c);
    else return true;
}

bool ok(char c) {
    rep(y,H) rep(x,W) {
        if(data[y][x]==c) {
            return dfs(y,x,0,c)&&dfs(y,x,1,c);
        }
    }
    return true;
}

void solve() {
    data.clear();
    cin>>H>>W;
    data.resize(H);
    rep(i,H) cin>>data[i];

    bool ans=true;
    rep(i,26) {
        ans &= ok(i+'A');
    }
    if(ans) cout<<"SAFE"<<endl;
    else cout<<"SUSPICIOUS"<<endl;

}

int main() {
    int n;
    cin>>n;
    while(n-->0) {
        solve();
    }
    return 0;
}

