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

struct Point {
    double x;
    double y;
};
void print(Point p) {
    printf("%.8f %.8f\n",p.x,p.y);
}

int n;

void koch(Point p1, Point p2,int depth) {
    if(n==depth) return;
    Point s;
    s.x = (2*p1.x+p2.x)/3;
    s.y = (2*p1.y+p2.y)/3;

    Point t;
    t.x = (p1.x+2*p2.x)/3;
    t.y = (p1.y+2*p2.y)/3;

    Point u;
    u.x=(t.x-s.x)/2-(t.y-s.y)*sqrt(3.0)/2+s.x;
    u.y=(t.x-s.x)*sqrt(3.0)/2+(t.y-s.y)/2+s.y;

    koch(p1,s,depth+1);
    print(s);
    koch(s,u,depth+1);
    print(u);
    koch(u,t,depth+1);
    print(t);
    koch(t,p2,depth+1);
}

int main() {
    cin>>n;
    Point p1,p2;
    p1.x=0;
    p1.y=0;
    p2.x=100;
    p2.y=0;
    print(p1);
    koch(p1,p2,0);
    print(p2);

    return 0;
}

