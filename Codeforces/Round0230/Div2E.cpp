#include<algorithm>
#include<functional>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<climits>

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define FOR(itr,data) for(__typeof((data).begin()) itr=(data).begin();itr!=(data).end();++itr)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

typedef unsigned long long UInt64;
typedef long long ll;

const int INF=100000000;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;
const int MOD = 1000000007;

typedef pair<int ,int > P;

ll mod_pow(ll x,ll n, ll mod) {
    ll res = 1;
    while(n > 0) {
        if(n&1) res = res * x % mod;
        x = x * x % mod;
        n >>=1;
    }
    return res;
}

mat mul(mat &A,mat &B) {
    mat C(A.size(),vec(B[0].size()));
    
    rep(i,A.size()) rep(k,B.size()) rep(j,B[0].size()) {
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    }

    return C;
}

mat pow(mat A,ll n) {
    mat B(A.size(),vec(A.size()));
    rep(i,A.size()) B[i][i]=1;

    while(n>0) {
        if(n&1) B=mul(B,A);
        A = mul(A,A);
        n>>=1;
    }

    return B;

}


int main() {
    int a = (-1)/2;
    cout<<a<<endl;
    ll n,k;
    cin>>n>>k;
    mat A(2,vec(2));
    A[0][0] = 1; A[0][1]=1;
    A[1][0] = 1; A[1][1]=0;
    A=pow(A,n);
    return 0;
}



