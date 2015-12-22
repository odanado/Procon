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

int main() {
    Combination<ll,1000006,1000000007 > comb;
    int T;
    scanf("%d",&T);
    char s[102];
    int n,r;

    rep(i,T) {
        scanf("%1s(%d,%d)",s,&n,&r);
        if(s[0]=='C') {
            cout<<comb.C(n,r)<<endl;
        }
        if(s[0]=='P') {
            cout<<comb.P(n,r)<<endl;
        }
        if(s[0]=='H') {
            cout<<comb.H(n,r)<<endl;
        }
    }

    return 0;
}

