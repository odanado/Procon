#include <iostream>
#include <complex>
#include <vector>
#include <cmath>
#include <utility>
#include <cassert>
#include <cmath>

const double EPS=1e-10;

#define equals(a, b) (fabs((a)-(b))<EPS)
#define X real()
#define Y imag()
#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

typedef complex<double> Point;
typedef complex<double> Vector;

struct Segment {
    Segment(Point p1, Point p2) : p1(p1), p2(p2){}
    Point p1, p2;
};
typedef Segment Line;

typedef vector<Point> Polygon;

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

void input(Point &p) {
    double a,b;
    cin>>a>>b;
    p.real(a);
    p.imag(b);
}

int main() {
    Point A,B;
    input(A);
    input(B);
    Segment s1(A,B);
    int N;
    cin>>N;
    Polygon poly;
    rep(i,N) {
        Point p;
        input(p);
        poly.push_back(p);
    }
    int cnt=0;
    rep(i,N+1) {
        int j=(i+1)%N;
        Segment s2(poly[i],poly[j]);
        if(intersect(s1,s2)) cnt++;
    }
    if(cnt==2) cout<<"2"<<endl;
    else cout<<cnt/2+1<<endl;
}

