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

double diff(double r,double x) {
    return r*pow(x,r-1);
}
double sum(double r, double x) {
    if(r==-1) {
        return log(x);
    }
    return pow(x,r+1)/(r+1);
}

int N;
double B;
double a[11];
int main() {
    cin>>N>>B;
    rep(i,N) cin>>a[i];
    double ans1=0;
    double ans2=0;
    rep(i,N) {
        //cout<<diff(a[i], B)<<endl;
        ans1+=diff(a[i], B);
        ans2+=sum(a[i], B);
    }
    printf("%.20f\n",ans1);
    printf("%.20f\n",ans2);
    return 0;
}

