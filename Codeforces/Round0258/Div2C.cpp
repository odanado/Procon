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

int t;
ll n,k;

// t1-t2<0? and t2-t3<0?
bool ok(ll d1,ll d2) {
    if(n%3) return false;
    ll x1 = k+2*d1+d2;
    if(x1%3!=0) return false;
    if(x1<0) return false;
    x1/=3;
    ll x2 = x1-d1;
    ll x3 = x2-d2;
    if(x2<0 || x3<0) return false;
    if(3*max(x1,max(x2,x3)) > n) return false;

    bool ret = true;
    ret &= x1+x2+x3==k;
    ret &= (x1-x2)==d1;
    ret &= (x2-x3)==d2;
    return ret;
}

bool solve() {
    ll d1,d2;
    cin>>n>>k>>d1>>d2;
    bool ret = false;
    ret |= ok(d1,d2);
    ret |= ok(-d1,d2);
    ret |= ok(d1,-d2);
    ret |= ok(-d1,-d2);

    return ret;

}
int main() {
    cin>>t;
    rep(i,t) {
        string ans = solve()?"yes":"no";
        cout<<ans<<endl;
    }
    return 0;
}

