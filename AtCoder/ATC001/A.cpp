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
const int MAX=1000;

string c[MAX];
bool visited[MAX][MAX]={};
int h,w;
bool dfs(int y,int x) {
    if(!(0<=y&&y<h)) return false;
    if(!(0<=x&&x<w)) return false;
    if(visited[y][x]) return false;
    if(c[y][x]=='#') return false;
    if(c[y][x]=='g') return true;
    visited[y][x]=true;
    bool ret=false;
    ret|=dfs(y+1,x);
    ret|=dfs(y,x+1);
    ret|=dfs(y-1,x);
    ret|=dfs(y,x-1);

    return ret;
}
int main() {
    rep(i,MAX) c[i]=string(MAX,'#');
    P s,t;
    cin>>h>>w;
    rep(y,h) rep(x,w) cin>>c[y][x];
    rep(y,h) rep(x,w) if(c[y][x]=='s') s=P(y,x);
    rep(y,h) rep(x,w) if(c[y][x]=='g') t=P(y,x);
    if(dfs(s.fr,s.sc)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;


    return 0;
}

