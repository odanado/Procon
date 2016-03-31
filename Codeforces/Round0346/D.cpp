#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <complex>
#include <vector>
#include <cmath>
#include <utility>
#include <cassert>
#include <cmath>

using namespace std;
using ll = long long;

#define all(c) (c).begin(), (c).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

const ll INF = 1e9;
const ll MOD = 1e9 + 7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

const double EPS = 1e-10;

#define equals(a, b) (fabs((a) - (b)) < EPS)
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
    Circle(Point c = Point(), double r = 0.0) : c(c), r(r) {}
};

typedef vector<Point> Polygon;

double dot(Vector a, Vector b) { return a.X * b.X + a.Y * b.Y; }

double cross(Vector a, Vector b) { return a.X * b.Y - a.Y * b.X; }

Point project(Segment s, Point p) {
    Vector base = s.p2 - s.p1;
    double r = dot(p - s.p1, base) / norm(base);
    return s.p1 + base * r;
}

Point reflect(Segment s, Point p) { return p + (project(s, p) - p) * 2.0; }

enum CCW {
    COUNTER_CLOCKWISE = 1,
    CLOCKWISE = -1,
    ONLINE_BACK = 2,
    ONLINE_FRONT = -2,
    ON_SEGMENT = 0,
};

int ccw(Point p0, Point p1, Point p2) {
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if (cross(a, b) > EPS) return CCW::COUNTER_CLOCKWISE;
    if (cross(a, b) < -EPS) return CCW::CLOCKWISE;
    if (dot(a, b) < -EPS) return CCW::ONLINE_BACK;
    if (norm(a) < norm(b)) return CCW::ONLINE_FRONT;

    return CCW::ON_SEGMENT;
}

vector<Point> points;
int n;
int main() {
    cin >> n;
    rep(i, n + 1) {
        double x, y;
        cin >> x >> y;
        points.push_back(Point{x, y});
    }
    int ans = 0;
    rep(i, n) if (i) {
        if (ccw(points[i - 1], points[i], points[i + 1]) ==
            CCW::COUNTER_CLOCKWISE)
            ans++;
    }
    cout << ans << endl;

    return 0;
}
