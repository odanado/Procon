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

const int inf=100000000;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
using namespace std;
typedef pair<int ,int > p;
typedef long long ll;

const double pi=acos(-1.0);

int n;
double r[1003];
int main() {
    cin>>n;
    double ans=0;
    rep(i,n) cin>>r[i];
    sort(r,r+n,[](double a,double b){return a>b;});
    rep(i,n) {
        if(i%2==0) ans+=r[i]*r[i];
        else ans-=r[i]*r[i];
    }
    printf("%.8f\n",ans*pi);
    return 0;
}

