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
#include <cassert>

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

const ll MOD=1000000007;
ll pow_mod(ll a,ll n) {
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
int N,Q;
int a[120004];
int c[120004];
ll b[120004];

ll getCost2(int v,int u) {
    if(u<v) swap(v,u);
    ll ret=0;
    for(int i=v;i<u;i++) {
        //printf("pow(%d, %d) = %lld\n",a[i],a[i+1],pow_mod(a[i],a[i+1]));
        ret+=pow_mod(a[i],a[i+1]);
        ret%=MOD;
    }

    //cout<<v<<"->"<<u<<": "<<ret<<endl;
    return ret;
}
ll getCost(int v,int u) {
    if(u<v) swap(v,u);
    return (b[u]-b[v]+MOD)%MOD;
}
ll solve2() {
    ll ans=0;
    ans=getCost2(0,c[0]);
    rep(i,Q) {
        ans+=getCost2(c[i],c[i+1]);
        ans%=MOD;
    }
    ans%=MOD;

    return ans;
}
int main() {
    cin>>N>>Q;
    rep(i,N) cin>>a[i];
    rep(i,Q) cin>>c[i];
    rep(i,Q) c[i]--;
    rep(i,N) if(i) b[i]=(b[i-1]+pow_mod(a[i-1],a[i]))%MOD;
    //rep(i,N) cout<<i<<": "<<b[i]<<endl;
    ll ans=0;
    ans=getCost(0,c[0]);
    rep(i,Q) {
        ans+=getCost(c[i],c[i+1]);
        ans%=MOD;
    }
    ans%=MOD;
    cout<<ans<<endl;
    return 0;
}

