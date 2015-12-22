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


struct Segment {
    Point p1, p2;
};

double dot(Vector a, Vector b) {
    return a.X*b.X + a.Y*b.Y;
}

double cross(Vector a,Vector b) {
    return a.X*b.Y - a.Y*b.X;
}

enum CCW {
    COUNTER_CLOCKWISE=1,
    CLOCKWISE=-1,
    ONLINE_BACK=2,
    ONLINE_FRONT=-2,
    ON_SEGMENT=0,
};

int ccw(Point p0, Point p1, Point p2) {
    Vector a=p1-p0;
    Vector b=p2-p0;
    if(cross(a,b)>EPS) return CCW::COUNTER_CLOCKWISE;
    if(cross(a,b)<-EPS) return CCW::CLOCKWISE;
    if(dot(a,b)<-EPS) return CCW::ONLINE_BACK;
    if(norm(a)<norm(b)) return CCW::ONLINE_FRONT;

    return CCW::ON_SEGMENT;
}

bool intersect(Point p1,Point p2,Point p3,Point p4) {
    return (ccw(p1,p2,p3)*ccw(p1,p2,p4)<=0&&
            ccw(p3,p4,p1)*ccw(p3,p4,p2)<=0);
}

bool intersect(Segment s1,Segment s2) {
    return intersect(s1.p1,s1.p2,s2.p1,s2.p2);
}

Point getCrossPoint(Segment s1,Segment s2) {
    Vector base=s2.p2-s2.p1;
    double d1=abs(cross(base,s1.p1-s2.p1));
    double d2=abs(cross(base,s1.p2-s2.p1));
    double t=d1/(d1+d2);
    return s1.p1+(s1.p2-s1.p1)*t;
}


Point a,b;
Point s[102],t[102];
int o[102],l[102];
vector<pair<double,int>> intersections;
int solve(int p) {
    int ret=0;
    rep(i,intersections.size()) {
        int t=intersections[i].sc;
        if(o[t]) {
            if(l[t]!=p) {
                ret++;
                p=l[t];
            }
        }
        else {
            if(l[t]==p) {
                ret++;
                p=l[t]^1;
            }
        }
    }

    return ret;
}

void solve() {
    intersections.clear();
    int n;
    cin>>n;
    rep(i,n) {
        int x1,y1;
        int x2,y2;
        cin>>x1>>y1>>x2>>y2>>o[i]>>l[i];
        s[i]=Point(x1,y1);
        t[i]=Point(x2,y2);
    }
    rep(i,n) {
        if(intersect(Segment{a,b},Segment{s[i],t[i]})) {
            Point p = getCrossPoint(Segment{a,b},Segment{s[i],t[i]});
            double d=abs(p-a);
            intersections.pb(mp(d,i));
        }
    }
    sort(all(intersections));
    cout<<min(solve(0),solve(1))<<endl;
}

int main() {
    int n;
    cin>>n;
    rep(i,n) {

        int x,y;
        cin>>x>>y;
        a.real(x);
        a.imag(y);
        cin>>x>>y;
        b.real(x);
        b.imag(y);
        solve();
    }
    return 0;
}

