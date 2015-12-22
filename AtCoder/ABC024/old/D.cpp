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

const int MOD=1e9+7;
ll A,B,C;


ll get_mod(ll a,ll mod) {
    return (a%mod+mod)%mod;
}
inline ll mod_pow(ll a, ll n, ll mod) {
    ll ret = 1;
    while(n > 0) {
        if(n & 1) {
            ret *= a;
            ret %= mod;
        }
        a *= a;
        a %= mod;

        n >>= 1;
    }

    return ret;
}
ll inv(ll a,ll mod) {
    return mod_pow(get_mod(a,mod),mod-2,mod)%mod;
}



int main() {
    cin>>A>>B>>C;

    ll c1 = get_mod(B*A-B*C+A*C,MOD);
    ll c2 = get_mod(B*C-A*C,MOD);

    ll r1 = get_mod(C*A-B*C+A*B,MOD);
    ll r2 = get_mod(B*C-A*B,MOD);

    ll ans1 = c2*inv(c1,MOD);
    ll ans2 = r2*inv(r1,MOD);


    ans1=get_mod(ans1,MOD);
    ans2=get_mod(ans2,MOD);
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}

