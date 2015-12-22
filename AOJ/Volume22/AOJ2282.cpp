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

// d*t<=m となる最大のt
int f(int d,int m) {
    int t=1;
    while(d*t<=m) t++;

    t--;
    // printf("%d * %d <= %d\n",d,t,m);
    return t*d;
}
int n,m;
int a[10004];
int times[10004];
void solve() {
    rep(i,n) cin>>a[i];
    times[0] = f(a[0],m);
    int min_time = times[0];
    
    rep(i,n) if(i) {
        int t=f(a[i],min_time)+a[i];
        if(m<t) {
            t=f(a[i],m);
        }
        times[i] = t;
        min_time = min(min_time,t);
    }
    min_time = *min_element(times,times+n);
    int cnt=0;
    rep(i,n) if(min_time==times[i]) {
        cnt++;
    }
    // rep(i,n) cout<<i<<" : "<<times[i]<<endl;
    if(cnt>1) {
        int t=-1;
        rep(i,n) if(min_time==times[i]) {
            // printf("%d %d\n",min_time, i);
            if(t==-1 || a[i]<a[t]) {
                t=i;
            }
        }
        int cnt2=0;
        rep(i,n) if(a[t]==a[i]) cnt2++;
        if(cnt2==1) cout<<t+1<<endl;
        else cout<<n<<endl;
    }
    else {
        int t=find(times,times+n,min_time)-times;
        cout<<t+1<<endl;
    }
}
int main() {
    while(cin>>n>>m) {
        if(n+m==0) break;
        solve();
    }
    return 0;
}

