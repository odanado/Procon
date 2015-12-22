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

template<class T,size_t N,T MOD>
struct Combination {
    typedef T int_type;
    vector<int_type> fact,factr,inv;
    Combination() {
        fact.resize(2*N+1);
        factr.resize(2*N+1);
        inv.resize(2*N+1);
        fact[0]=factr[0]=1;
        inv[1]=1;
        for(int i=2;i<=2*N;i++) inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
        for(int i=1;i<=2*N;i++) fact[i]=fact[i-1]*i%MOD, factr[i]=factr[i-1]*inv[i]%MOD;
    }

    int_type C(int n, int r) {
        if(r<0 || r>n) return 0;
        return factr[r]*fact[n]%MOD*factr[n-r]%MOD;
    }

    int_type P(int n,int r) {
        if(r<0 || r>n) return 0;
        return fact[n]*factr[n-r]%MOD;
    }

    int_type H(int n, int r) {
        if(n==0 && r==0) return 1;
        return C(n+r-1,r);
    }
};
const ll MOD=1000000007;

ll dp[2003][2003];
ll s[2003];
ll N,D,X;

Combination<ll,2003,MOD> comb;

ll C(ll d,ll n) {
    ll ret=comb.factr[n];
    rep(i,n) {
        ret*=(d%MOD);
        ret%=MOD;
        d--;
    }

    return ret;
}

void solve() {
    memset(dp,0,sizeof(dp));
    memset(s,0,sizeof(s));
    dp[0][0]=1;
    rep(i,N+1) if(i) rep(j,N+1) {
        rep(k,X) if(k){
            if(j-k<0) continue;
            dp[i][j]+=dp[i-1][j-k];
            dp[i][j]%=MOD;
        }
    }
    ll ans=0;
    //rep(i,X) rep(j,X) rep(k,X) if(i+j+k==X) printf("%d %d %d\n",i,j,k);
    rep(i,N+1) {
        //printf("%d: %lld %lld\n", i,dp[i][N],C(D,i));
        ans+=(dp[i][N]*C(D,i))%MOD;
        ans%=MOD;
    }
    cout<<ans<<endl;
}

int main() {
    while(cin>>N>>D>>X) {
        if(N==0) break;
        solve();
    }
    return 0;
}

