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
typedef long long ll;

int popcount(int x) {
    return __builtin_popcount(x);
    int ret=0;
    while(x) {
        if(x&1) ret++;
        x>>=1;
    }
    return ret;
}
int N,M,P,Q,R;
int x[4000],y[4000],z[4000];
int main() {
    cin>>N>>M>>P>>Q>>R;
    rep(i,R) cin>>x[i]>>y[i]>>z[i];
    rep(i,R) x[i]--;
    rep(i,R) y[i]--;
    if(N>=9||M>=9) return 0;

    int ans=0;
    rep(s1,1<<N) rep(s2,1<<M) {
        if(popcount(s1)!=P||popcount(s2)!=Q) continue;
        int t=0;
        rep(i,R) {
            if((s1>>x[i]&1) && (s2>>y[i]&1)) t+=z[i];
        }
        ans=max(ans,t);
    }

    cout<<ans<<endl;


    return 0;
}

