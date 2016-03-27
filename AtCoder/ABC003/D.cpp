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
#include <cassert>

using namespace std;
using ll = long long;

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

const ll INF=1e9;
const ll MOD=1e9+7;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

/*
 * 前処理 O(N)
 * クエリ O(1)
 *
 * Verified
 * http://yukicoder.me/problems/184
 */

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
        if(n<0 || r<0 || r>n) return 0;
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


Combination<ll, 1003, MOD> comb;

int R,C;
int X,Y;
int D,L;
int a[31][31];
// x*yの長方形に机D個,サーバL個を敷き詰める時の場合の数
// 空白を考慮している
ll f(int x,int y) {
    if(x<0||y<0) return 0;
    if(x*y<D+L) return 0;
    ll ret = 0;
    // 机
    ret += comb.C(x*y,D);
    ret %= MOD;
    // 残りのx*y-Dマスにサーバを置く
    ret *= comb.C(x*y-D,L);
    ret %= MOD;
    return ret;
}
int main() {
    cin>>R>>C;
    cin>>X>>Y;
    cin>>D>>L;
    ll ans = 0;
    ans = f(X,Y)-2*f(X-1,Y)-2*f(X,Y-1)+4*f(X-1,Y-1)+f(X-2,Y)+f(X,Y-2)-2*f(X-2,Y-1)-2*f(X-1,Y-2)+f(X-2,Y-2);
    ans *= (R-X+1)*(C-Y+1);
    ans %= MOD;
    ans += MOD;
    ans %= MOD;
    cout<<ans<<endl;
    return 0;
}

