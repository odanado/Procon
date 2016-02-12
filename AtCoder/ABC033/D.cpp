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


#include <complex>
#include <vector>
#include <cmath>
#include <utility>
#include <cassert>
#include <cmath>

const double EPS=1e-10;
const double PI=acos(-1.0);

#define equals(a, b) (fabs((a)-(b))<EPS)
#define X real()
#define Y imag()

using namespace std;

typedef complex<double> Point;
typedef complex<double> Vector;

struct Segment {
    Point p1, p2;
};
typedef Segment Line;

struct Circle {
    Point c;
    double r;
    Circle(Point c=Point(), double r=0.0) :
        c(c),r(r){}
};

typedef vector<Point> Polygon;

double dot(Vector a, Vector b) {
    return a.X*b.X + a.Y*b.Y;
}

double cross(Vector a,Vector b) {
    return a.X*b.Y - a.Y*b.X;
}

Point project(Segment s, Point p) {
    Vector base = s.p2-s.p1;
    double r=dot(p-s.p1,base) / norm(base);
    return s.p1+base*r;
}

Point reflect(Segment s, Point p) {
    return p+(project(s,p)-p)*2.0;
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

double getDistance(Point a,Point b) {
    return abs(a-b);
}

double getDistanceLP(Line l, Point p) {
    return abs(cross(l.p2-l.p1,p-l.p1)/abs(l.p2-l.p1));
}

bool intersect(Point p1,Point p2,Point p3,Point p4) {
    return (ccw(p1,p2,p3)*ccw(p1,p2,p4)<=0&&
            ccw(p3,p4,p1)*ccw(p3,p4,p2)<=0);
}

bool intersect(Segment s1,Segment s2) {
    return intersect(s1.p1,s1.p2,s2.p1,s2.p2);
}
bool intersect(Circle c,Line l) {
    return getDistanceLP(l,c.r)<=c.r;
}

Point getCrossPoint(Segment s1,Segment s2) {
    Vector base=s2.p2-s2.p1;
    double d1=abs(cross(base,s1.p1-s2.p1));
    double d2=abs(cross(base,s1.p2-s2.p1));
    double t=d1/(d1+d2);
    return s1.p1+(s1.p2-s1.p1)*t;
}
pair<Point, Point> getCrossPoints(Circle c, Line l) {
    // assert(intersect(c,l));
    Vector pr=project(l,c.c);
    Vector e=(l.p2-l.p1)/abs(l.p2-l.p1);
    double base=sqrt(c.r*c.r-norm(pr-c.c));

    return make_pair(pr+e*base,pr-e*base);

}

pair<Point,Point> getCrossPoints(Circle c1, Circle c2) {
    double d=abs(c1.c-c2.c);
    double a=acos((c1.r*c1.r+d*d-c2.r*c2.r)/(2*c1.r*d));
    double t=arg(c2.c-c1.c);

    return make_pair(c1.c+polar(c1.r,t+a),c1.c+polar(c1.r,t-a));
}

// IN 2, ON 1, OUT 0
int contains(Polygon g, Point p) {
    int n=g.size();
    bool x=false;
    for(int i=0;i<n;i++) {
        Point a=g[i]-p,b=g[(i+1)%n]-p;
        if(abs(cross(a,b))<EPS && dot(a,b)<EPS) return 1;
        if(a.Y>b.Y) swap(a,b);
        if(a.Y<EPS&&EPS<b.Y&&cross(a,b) > EPS) x=!x;
    }

    return x?2:0;
}

double f(Point p1, Point p2, Point p3) {
    Vector vec1=p1-p2;
    Vector vec2=p1-p3;
    return dot(vec1,vec2);
}

ll ans1,ans2,ans3;
int N;
Point p[2003];
int main() {
    cin>>N;
    rep(i,N) {
        int x,y;
        cin>>x>>y;
        p[i]=Point(x,y);
    }
    rep(i,N) {
        vector<double> vec;
        rep(j,N) if(i!=j) {
            Vector t=p[i]-p[j];
            vec.push_back(arg(t));
        }
        sort(all(vec));
        rep(j,N-1) vec.push_back(vec[j]+PI*2);
        rep(j,N-1) {
            //if(i==0) cout<<vec[j]/PI*180<<endl;
            // PI/2未満
            int t1=lower_bound(all(vec),vec[j]+PI/2-EPS)-vec.begin();
            // PI/2以下
            int t2=upper_bound(all(vec),vec[j]+PI/2+EPS)-vec.begin();
            // PI未満
            int t3=lower_bound(all(vec),vec[j]+PI-EPS)-vec.begin();
            ans2 += t2-t1;
            ans3 += t3-t2;
        }
    }
    ans1=(1LL*N*(N-1)*(N-2))/6-ans3-ans2;
    cout<<ans1<<" "<<ans2<<" "<<ans3<<endl;
    return 0;
}

