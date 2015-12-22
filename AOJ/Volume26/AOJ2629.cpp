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

double d;
double f(double y) {
    return y*y*(d*d-y*y);
}
int main() {
    cin>>d;
    double l,r;
    l=0;
    r=10;
    rep(i,1000) {
        if (f((l * 2 + r) / 3) > f((l + r * 2) / 3)){
            r = (l + r * 2) / 3;
        } else {
            l = (l * 2 + r) / 3;
        }
    }
    double ans=(r+l)/2;
    ans=sqrt(ans);
    ans=sqrt(d*d+2*ans*ans);
    printf("%.20f\n",ans);
    return 0;
}

