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

const double INF=1e11;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
using namespace std;
typedef pair<int ,int > P;
typedef long long ll;

double f2(double a[4],double mid,int S) {
    double x[4]={mid,mid,mid,mid};
    rep(i,4) if((S>>i)&1) x[i]=-x[i];

    return (a[0]+x[0])*(a[1]*x[1])-(a[2]*x[2])*(a[3]*x[3]);

}
double f(double a,double b,double c,double d,int S) {
    double ary[]={a,b,c,d};
    double l=0,r=INF;

    rep(i,100000) {
        double mid=(l+r)/2;
        if(f2(ary,mid,S)<0) l=mid;
        else r=mid;
    }

    printf("%d : %.2f\n",S,l);
    return l;
}

int main() {
    double a1,b1,c1,d1;
    cin>>a1>>b1>>c1>>d1;
    double ans=INF;

    rep(i,1<<4) {
        double a=a1;
        double b=b1;
        double c=c1;
        double d=d1;
        ans=min(ans,f(a,b,c,d,i));
    }

    printf("%.9f\n",ans);

    return 0;
}

