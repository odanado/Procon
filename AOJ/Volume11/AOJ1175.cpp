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
#include <complex>


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
typedef complex<double> Point;


struct Circle {
    Point c;
    double r;
    int color;
    Circle(Point c=Point(), double r=0.0,int color=0) :
        c(c),r(r),color(color){}
};
double getDistance(Point a,Point b) {
    return abs(a-b);
}

bool intersect(Circle c1, Circle c2) {
    double d=getDistance(c1.c,c2.c);
    return d<c1.r+c2.r;
}
int n;
bool same_color[30][30];
bool is_intersect[30][30];
bool ok(int n,int S) {
    rep(i,n) {
        if(!(S>>i&1)&&is_intersect[i][n]) return false;
    }

    return true;
}
short dp[1<<24];
int dfs(int S) {
    if(dp[S]!=-1) return dp[S];
    int ret=0;
    rep(i,n) rep(j,n) if(i!=j) {
        if(((S>>i)&1)) continue;
        if(((S>>j)&1)) continue;
        if(!same_color[i][j]) continue;
        //if(!ok(i,S)) continue;
        //if(!ok(j,S)) continue;
        bool ok=true;
        rep(k,n) {
            if(((S>>k)&1)) continue;
            if(k<i&&is_intersect[i][k]) ok=false;
            if(k<j&&is_intersect[j][k]) ok=false;
        }
        if(!ok) continue;

        //printf("remove %d %d\n",i,j);
        ret=max(ret,dfs(S|(1<<i)|(1<<j))+2);
    }

    return dp[S]=ret;
}
void solve() {
    memset(dp,-1,sizeof(dp));
    rep(i,30) rep(j,30) is_intersect[i][j]=false;
    rep(i,30) rep(j,30) same_color[i][j]=false;
    vector<Circle> circles;
    rep(i,n) {
        double x,y,r;
        int c;
        cin>>x>>y>>r>>c;
        circles.push_back(Circle(Point{x,y},r,c));
    }
    rep(i,circles.size()) rep(j,circles.size()) {
        if(intersect(circles[i],circles[j])) is_intersect[i][j]=true;
        if(circles[i].color==circles[j].color) same_color[i][j]=true;
    }
    cout<<dfs(0)<<endl;
}
int main() {
    while(cin>>n) {
        if(!n) break;
        solve();
    }
    return 0;
}

