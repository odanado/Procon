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

int N;
int a[100005];
ll cnt[100005];
const int MOD=1e9+7;
ll mod_pow(ll a,ll n,ll m) {
    //cout<<a<<", "<<n<<" : ";
    ll ret=1;
    while(n) {
        if(n&1) {
            ret*=a;
            ret%=m;
        }

        a*=a;
        a%=m;
        n>>=1;
    }
    //cout<<ret<<endl;

    return ret%MOD;
}
int main() {
    cin>>N;
    rep(i,N) cin>>a[i];
    rep(i,N) cnt[a[i]]++;
    set<int> S;
    rep(i,N) S.insert(a[i]);
    ll ans=1;
    if(a[0]!=0) ans=0;
    if(cnt[0]>1) ans=0;
    if(cnt[0]==0) ans=0;
    for(auto i:S) if(i) {
        //printf("[debug] %d %d\n",cnt[a[i]-1],b[a[i]]);
        ll c=cnt[i-1];
        ll x=cnt[i];
        //printf("%d %d\n",c,x);
        ll t=1;
        //ll t=mod_pow(2,c,MOD)-1;
           
        t=t*(mod_pow(2,c,MOD)-1)%MOD;

        t=mod_pow(t,x,MOD);
        t=t*(mod_pow(2,x*(x-1)/2,MOD))%MOD;
        //cout<<t<<endl;
        t%=MOD;
        ans*=t;
        ans%=MOD;
    }
    cout<<ans<<endl;

    return 0;
}

