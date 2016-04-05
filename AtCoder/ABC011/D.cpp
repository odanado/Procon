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

double C[1003][1003];

double comb(int n,int r) {
    //cout<<"debug: "<<n<<", "<<r<<endl;
    if(n<0||r<0||n<r) return 0;
    assert(n>=0&&r>=0);
    assert(n>=r);
    return C[n][r];
}
int main() {
    C[0][0]=1;
    rep(i,1002) rep(j,1002) if(j<=i) {
        C[i+1][j]+=C[i][j]/2;
        C[i+1][j+1]+=C[i][j]/2;
    }
    int N,D;
    int X,Y;
    cin>>N>>D>>X>>Y;
    X=abs(X);
    Y=abs(Y);
    if(X%D!=0||X%D!=0) {
        cout<<"0.0"<<endl;
        return 0;
    }
    X/=D;
    Y/=D;
    double ans=0.0;
    rep(i,N+1) {
        if((i+X)%2!=0) continue;
        if((N-i+Y)%2!=0) continue;
        ans+=comb(N,i)*comb(i,(i+X)/2)*comb(N-i,(N-i+Y)/2);
    }
    printf("%.12f\n",ans);
    return 0;
}

