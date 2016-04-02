#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
using ll = long long;

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

#define int long long
const ll INF=1e9;
const ll MOD=1e9+7;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int t1,t2,t3;
signed main() {
    cin>>t1>>t2>>t3;
    int lcm;
    lcm=t1/__gcd(t1,t2)*t2;
    lcm=lcm/__gcd(t3,lcm)*t3;
    int ans=1;
    rep(i,10004) if(i) {
        if(lcm/t1%i==lcm/t2%i&&lcm/t2%i==lcm/t3%i) ans=max(ans,i);
    }

    int g=__gcd(lcm,ans);
    lcm/=g;
    ans/=g;
    cout<<lcm<<"/"<<ans<<endl;

    return 0;
}

