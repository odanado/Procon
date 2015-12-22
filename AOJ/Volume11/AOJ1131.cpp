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


int p,q,a,n;
int ans;
double in;

inline bool equal(double d1,double d2,double eps=1e-8) {
    return ((d1-eps)<d2 && (d2<(d1+eps)));
}

void dfs(int cnt,int den, int mul, double r) {
    if(cnt==n+1) {
        return;
    }
    if(in<r-1e-8) return;

    if(equal(in,r)) {
        //cout<<"count"<<endl;
        ans++;
    }
    // cout<<cnt<<","<<den<<","<<r<<endl;

    for(int i=den;i*mul<=a;i++) {
        //cout<<cnt<<","<<den<<" : "<<r<<" + "<<Ratio(1,i)<<" = "<<r+Ratio(1,i)<<endl;
        dfs(cnt+1,i,mul*i, r+1.0/i );
    }

}


void solve() {
    ans=0;
    in=1.0*p/q;
    dfs(0,1,1, 0);
    cout<<ans<<endl;

}

int main() {
    while(cin>>p>>q>>a>>n) {
        if(!p) break;
        solve();
    }
    return 0;
}

