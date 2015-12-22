#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
#include <cstdint>
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
typedef complex<double> P;
int n;

double cross(P p1,P p2) {
    return (real(p1)*imag(p2) - imag(p1)*real(p2));
}
double calc_S(P p1,P p2,P p3) {
    double ret = 0.0;
    p1 -= p3;
    p2 -= p3;

    ret = cross(p1,p2)/2.0;
    
    return abs(ret);
}

int main() {
    cin>>n;
    while(n-->0) {
        double x1_,y1_;
        double x2_,y2_;
        double x3_,y3_;
        cin>>x1_>>y1_>>x2_>>y2_>>x3_>>y3_;
        P p1(x1_,y1_);
        P p2(x2_,y2_);
        P p3(x3_,y3_);
        P A = p1-p2;
        P B = p2-p3;
        P C = p1-p3;
        double S = calc_S(p1,p2,p3);
        double R = abs(A)*abs(B)*abs(C)/S;
        R /= 4.0;
        
        P A1 = 2.0*(p2-p1);
        P B1 = 2.0*(p3-p1);
        P C1 = P(norm(p1)-norm(p2),norm(p1)-norm(p3));
        double X = cross(P(imag(A1),imag(B1)),C1)/cross(A1,B1);
        double Y = cross(C1,P(real(A1),real(B1)))/cross(A1,B1);
        printf("%.3lf %.3lf %.3lf\n",X,Y,R);

    }
    return 0;
}

