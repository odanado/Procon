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
const double PI=acos(-1.0);

double a,b,c;
double ans;
vector<double> vec;
int main() {
    cin>>a>>b>>c;
    vec.pb(a);
    vec.pb(b);
    vec.pb(c);
    double s=a+b+c;
    ans+=s*s*PI;
    sort(all(vec));
    double t=vec[2]-vec[0]-vec[1];
    if(t>0) ans-=t*t*PI;
    printf("%.20f\n",ans);
    return 0;
}

