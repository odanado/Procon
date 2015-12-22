#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
#include <cstdint>
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
const int MOD = 1000000007;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
using namespace std;
typedef pair<int ,int > P;

int64_t x,y;

typedef vector<int64_t> vec;
typedef vector<vec> mat;

int64_t mod(int64_t n) {
    while(1) {
        if(n>=0) break;
        n += MOD;
    }
    n%=MOD;
    return n;
}
mat mul(mat &A,mat &B) {
    mat C(A.size(),vec(B[0].size()));
    rep(i,A.size()) rep(k,B.size()) rep(j,B[0].size()) {
        C[i][j] = mod(C[i][j]+A[i][k]*B[k][j]);
    }
    return C;
}

mat pow(mat A,int64_t n) {
    mat B(A.size(),vec(A.size()));
    rep(i,A.size()) {
        B[i][i]=1;
    }
    while(n > 0) {
        if(n&1) B = mul(B,A);
        A = mul(A,A);
        n>>=1;
    }
    return B;
}
int main() {
    int64_t n;
    cin>>x>>y;
    cin>>n;
    x=mod(x);
    y=mod(y);
    mat A(2,vec(2));
    A[0][0] = 1;
    A[0][1] = -1;
    A[1][0] = 1;
    A[1][1] = 0;

    A = pow(A,n-1);
    int64_t ans = A[1][0] * y;
    ans = mod(ans);
    ans += A[1][1] * x;
    ans = mod(ans);
    cout<<ans<<endl;
    return 0;
}

