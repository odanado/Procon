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

const double EPS=1e-10;

#define equals(a, b) (fabs((a)-(b))<EPS)
#define X real()
#define Y imag()

typedef complex<double> Point;
typedef complex<double> Vector;


struct Circle {
    Point c;
    double r;
    Circle(Point c=Point(), double r=0.0) :
        c(c),r(r){}
};

struct Segment {
    Point p1, p2;
};

bool include(Circle c,Point p) {
    return (norm(c.c-p) <= c.r*c.r+EPS);
}

int n;
double xs[301],ys[301];

Point getMidpoint(Point p1, Point p2, Point p3) {
    Point p=p1+p2+p3;
    p/=3;

    return p;
}

int f(Point p) {
    int ret=0;
    Circle c=Circle(p,1);
    rep(i,n) {
        if(include(c,Point{xs[i],ys[i]})) ret++;
    }

    return ret;
}

void solve() {
    rep(i,n) cin>>xs[i]>>ys[i];
    int ans=1;
    rep(i,n) rep(j,n) if(i<j) {
        Point p1=Point{xs[i],ys[i]};
        Point p2=Point{xs[j],ys[j]};
        Vector v=p1-p2;
        if(abs(v) > 2.0+EPS) continue;
        
        Vector t=(v/abs(v))*Vector(0,1);
        double h=sqrt(1-abs(v)*abs(v)/4.0);

        Point p = p2+v/2.0 + t*h;


        ans=max(ans,f(p));
        t*=-1.0;
        p = p2+v/2.0 + t*h;
        ans=max(ans,f(p));
    }

    cout<<ans<<endl;
}

int main() {
    while(cin>>n) {
        if(!n) break;
        solve();
    }
    return 0;
}

