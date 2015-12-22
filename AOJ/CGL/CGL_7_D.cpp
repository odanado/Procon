#include <iostream>

#include <complex>
#include <vector>
#include <cmath>
#include <utility>
#include <cassert>
#include <algorithm>

const double EPS=1e-10;

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
    double d=getDistanceLP(l,c.c);
    return !(d>c.r);
}

Point getCrossPoint(Segment s1,Segment s2) {
    Vector base=s2.p2-s2.p1;
    double d1=abs(cross(base,s1.p1-s2.p1));
    double d2=abs(cross(base,s1.p2-s2.p1));
    double t=d1/(d1+d2);
    return s1.p1+(s1.p2-s1.p1)*t;
}
pair<Point, Point> getCrossPoints(Circle c, Line l) {
    assert(intersect(c,l));
    Vector pr=project(l,c.c);
    Vector e=(l.p2-l.p1)/abs(l.p2-l.p1);
    double base=sqrt(c.r*c.r-norm(pr-c.c));

    return make_pair(pr+e*base,pr-e*base);

}

int main() {
    double cx,cy,r;
    cin>>cx>>cy>>r;
    Circle circle({Point(cx,cy),r});
    int q; cin>>q;
    while(q-->0) {
        double x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        Line l=Line({Point(x1,y1),Point(x2,y2)});

        auto ans=getCrossPoints(circle,l);
        vector<pair<double,double>> vec;
        vec.push_back(make_pair(ans.first.X,ans.first.Y));
        vec.push_back(make_pair(ans.second.X,ans.second.Y));
        sort(vec.begin(),vec.end());
        printf("%.10f %.10f ",vec[0].first,vec[0].second);
        printf("%.10f %.10f\n",vec[1].first,vec[1].second);
    }
    return 0;
}

