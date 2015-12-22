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
int n,m;
string a[502];
string b[502];

bool ok(int y,int x) {
    bool ret=true;
    rep(k,4) {
        int ny=y+dy[k];
        int nx=x+dx[k];
        //if(ny<0||nx<0) continue;
        //if(n<=ny||m<=nx) continue;
        if(ny<0||nx<0) return false;
        if(n<=ny||m<=nx) return false;
        ret&=b[ny][nx]>'0';
    }
    return ret;
}
void func(int y,int x) {
    rep(k,4) {
        int ny=y+dy[k];
        int nx=x+dx[k];
        if(ny<0||nx<0) continue;
        if(n<=ny||m<=nx) continue;
        b[ny][nx]--;
    }
}

int main() {
    cin>>n>>m;
    rep(y,n) cin>>b[y];
    rep(y,n) a[y]=string(m,'0');
    rep(y,n) rep(x,m) {
        while(ok(y,x)) {
            a[y][x]++;
            func(y,x);
        }
    }
    rep(y,n) {
        cout<<a[y]<<endl;
    }
    return 0;
}

