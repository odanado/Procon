#include <complex>
#include <vector>
#include <cmath>
#include <iostream>

const double EPS=1e-10;

#define equals(a, b) (fabs((a)-(b))<EPS)
#define X real()
#define Y imag()

using namespace std;

typedef complex<double> Point;
typedef Point Vector;

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

int main(void) {
    int n;
    cin>>n;
    while(n-->0) {
        double x1,y1;
        double x2,y2;
        double x3,y3;
        double x4,y4;
        cin>>x1>>y1;
        cin>>x2>>y2;
        cin>>x3>>y3;
        cin>>x4>>y4;
        Segment s1,s2;
        s1.p1=Point(x1,y1);
        s1.p2=Point(x2,y2);
        s2.p1=Point(x3,y3);
        s2.p2=Point(x4,y4);
        if(equals(dot(s1.p2-s1.p1,s2.p2-s2.p1),0.0)) {
            cout<<"1"<<endl;
        }
        else if(equals(cross(s1.p2-s1.p1,s2.p2-s2.p1),0.0)) {
            cout<<"2"<<endl;
        }
        else cout<<"0"<<endl;
    }
    return 0;
}
