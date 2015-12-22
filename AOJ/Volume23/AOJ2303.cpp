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
typedef long long ll;
typedef pair<int,int> Pi;

ll C[51][51];
int N,M,L;
int P[102],T[102],V[102];
double A[102][51];
double B[102][51];

double f(int a,int b) {
    double ret=A[a][b];
    rep(i,N) if(a!=i) {
        double p=0;
        rep(j,M+1) {
            if(B[a][b]<B[i][j]) p+=A[i][j];
        }
        ret*=p;
    }

    return ret;
}
int main() {
    rep(i,51) C[i][0]=1;
    rep(i,51) for(int j=1;j<=i;j++) C[i][j]=C[i-1][j-1]+C[i-1][j];

    cin>>N>>M>>L;
    rep(i,N) cin>>P[i]>>T[i]>>V[i];

    rep(i,N) {
        // j回休む
        rep(j,M+1) {
            double p=C[M][j];
            rep(k,j) p*=P[i]/100.0;
            rep(k,M-j) p*=(100-P[i])/100.0;
            A[i][j]=p;

            double t=0;
            t+=j*T[i];
            t+=1.0*L/V[i];
            B[i][j]=t;
        }
    }

    double ans[102];

    rep(i,N) {
        ans[i]=0;
        rep(j,M+1) {
            ans[i]+=f(i,j);
        }
    }
    rep(i,N) printf("%.20f\n",ans[i]);



    return 0;
}

