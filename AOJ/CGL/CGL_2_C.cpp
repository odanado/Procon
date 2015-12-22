#include <iostream>
#include <complex>
#include <vector>
#include <cmath>

const double EPS=1e-10;

#define equals(a, b) (fabs((a)-b(b))<EPS)
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
int main() {
    int q;
    cin>>q;
    while(q-->0) {
        double x1,y1;
        double x2,y2;
        double x3,y3;
        double x4,y4;
        cin>>x1>>y1>>x2>>y2;
        cin>>x3>>y3>>x4>>y4;
        Segment s1=Segment({Point(x1,y1),Point(x2,y2)});
        Segment s2=Segment({Point(x3,y3),Point(x4,y4)});

        Point p=getCrossPoint(s1,s2);
        printf("%.10f %.10f\n",p.X,p.Y);
    }
    return 0;
}

