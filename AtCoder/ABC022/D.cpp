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
typedef long long ll;
const double PI = acos(-1.0);

struct P {
    double x,y;
    double eps;
    P(double x=0,double y=0) :
        x(x),y(y){}
    void shift(double r) {
        x+=r;
        y+=r;
        eps=1e-8;
    }

    void rot(double theta) {
        double t=theta*PI/180.0;
        double xx=x;
        double yy=y;
        x=xx*cos(t)-yy*sin(t);
        y=xx*sin(t)+yy*cos(t);
    }

    void mul(double p) {
        x*=p;
        y*=p;
    }

    void serialize() {
        if(x<eps) x=0;
        if(y<eps) y=0;
    }

    bool operator==(const P& rth) const {
        return x==rth.x && y==rth.y;
    }


};

int n;
int Ax[100005];
int Ay[100005];
int Bx[100005];
int By[100005];

int main() {
    cin>>n;
    rep(i,n) cin>>Ax[i]>>Ay[i];
    rep(i,n) cin>>Bx[i]>>By[i];

    return 0;
}

