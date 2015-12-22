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

int mod_pow(int a,int n,int m) {
    int ret=1;
    while(n) {
        if(n&1) {
            ret*=a;
            ret%=m;
        }
        a*=a;
        a%=m;
        n>>=1;
    }

    return ret;
}

int N,M,A,B,C,T;
int S[60];

int get_S(int i) {
    if(i<0||N<=i) return 0;
    return S[i];
}

vector<vector<int> > mul(vector<vector<int> > &A, vector<vector<int> > &B) {
    vector<vector<int> > C(A.size(),vector<int>(B[0].size()));
    
    rep(i,A.size()) rep(k,B.size()) rep(j,B[k].size()) {
        C[i][j]=(C[i][j]+A[i][k]*B[k][j])%M;
    }

    return C;
}
vector<vector<int> > mod_pow(vector<vector<int> > mat,int n,int m) {
    vector<vector<int> > ret(mat.size(),vector<int>(mat.size()));
    rep(i,ret.size()) ret[i][i]=1;
    while(n) {
        if(n&1) ret=mul(ret,mat);
        mat=mul(mat,mat);
        n>>=1;
    }

    return ret;
}

void solve() {
    vector<vector<int> > mat(N,vector<int>(N));
    rep(i,N) {
        int a=i-1;
        int b=i;
        int c=i+1;
        if(a>=0) mat[i][a]=A;
        mat[i][b]=B;
        if(c<N) mat[i][c]=C;
    }
    mat=mod_pow(mat,T,M);

    rep(i,N) {
        int ans=0;
        rep(j,N) {
            ans+=mat[i][j]*get_S(j);
            ans%=M;
        }
        cout<<ans;;
        if(i==N-1) cout<<endl;
        else cout<<" ";
    }

}

int main() {
    while(cin>>N>>M>>A>>B>>C>>T) {
        if(N==0) break;
        rep(i,60) S[i]=0;
        rep(i,N) cin>>S[i];
        solve();
    }
    return 0;
}

