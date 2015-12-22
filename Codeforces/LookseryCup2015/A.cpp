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
int dx[4]={0,0,1,1};
int dy[4]={0,1,0,1};
using namespace std;
typedef pair<int ,int > P;
typedef long long ll;

int h,w;
string board[100];
bool ok(int y,int x) {
    string s="";
    rep(k,4) {
        int ny=y+dy[k];
        int nx=x+dx[k];
        if(h<=ny) continue;
        if(w<=nx) continue;
        s+=board[ny][nx];
    }
    if(s.size()!=4) return false;
    sort(all(s));
    string face="face";
    sort(all(face));

    return face==s;
}
int main() {
    cin>>h>>w;
    rep(y,h) cin>>board[y];
    int ans=0;
    rep(y,h) rep(x,w) if(ok(y,x)) ans++;
    cout<<ans<<endl;
    return 0;
}

