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
const double PI=acos(-1);
const double EPS=1e-13;
const double EPS2=1e-6;
#define equl(a,b) abs(a-b)<=EPS
#define equl2(a,b) abs(a-b)<=EPS2

double A,B,C;
double f(double t) {
    return A*t+B*sin(C*t*PI);
}
int main() {
    cin>>A>>B>>C;
    double s=0;
    double t=INF;

    rep(i,1000) {
        double mid=(s+t)/2;
        if(f(mid)-100<0) s=mid;
        else t=mid;
    }
    printf("%.20f\n",s);
    return 0;
}

