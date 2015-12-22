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
const int MOD= 1000000007;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
using namespace std;
typedef pair<int ,int > P;
typedef long long ll;

ll lcm(ll a,ll b) {
    return a/__gcd(a,b)*b;
}

void solve(ll N,ll K) {
    ll ans=0;
    rep(i,N+1) if(i) ans=(ans+lcm(i,K))%MOD;
    cout<<ans<<endl;
}

ll mod_pow(ll a, int n) {
    ll ret=1;
    while(n) {
        if(n&1) {
            ret*=a;
            ret%=MOD;
        }
        a*=a;
        a%=MOD;
        n>>=1;
    }

    return ret;
}

ll inv(ll a) {
    return mod_pow(a,MOD-2);
}

void f(ll N,ll K) {
    rep(i,N+1) if(i) {
        printf("%d %lld %lld: %lld\n",i,K,__gcd((ll)i,K),lcm(i,K));
    }
}

ll N,K;
int main() {
    cin>>N>>K;
    ll ans=0;
    if(K>100) return 0;
    //solve(N,K);
    rep(i,K)  {
        // 余りi
        // 個数
        ll t=(N-i)/K;

        ll f=i;
        ll l=t*K+i;

        if(N<f) continue;
        t=(l-f)/K;
        //printf("%d: %d - %d %d\n",i,f,l,t);
        ll s=(f+l)*(t+1)%MOD*inv(2)%MOD;
        ans+=s*K%MOD*inv(__gcd((ll)i,K))%MOD;
        ans%=MOD;
    }
    cout<<ans<<endl;
    
    return 0;
}

