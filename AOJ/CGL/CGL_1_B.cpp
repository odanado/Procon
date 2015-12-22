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

int main() {
    Segment s;
    {
        double x1,y1;
        double x2,y2;
        cin>>x1>>y1>>x2>>y2;
        s=Segment({Point(x1,y1),Point(x2,y2)});

    }
    int q;
    cin>>q;
    while(q-->0) {
        double x1,y1;
        cin>>x1>>y1;
        Point p=Point(x1,y1);
        Point x=reflect(s,p);
        printf("%.10f %.10f\n",x.X,x.Y);
    }
}
