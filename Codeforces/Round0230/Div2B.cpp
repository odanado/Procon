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
typedef long long Int64;

const int INF=100000000;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

using namespace std;

typedef pair<int ,int > P;

int n;
double W[180][180];
double A[180][180];
double B[180][180];

int main() {
    cin>>n;
    rep(i,n) rep(j,n) cin>>W[i][j];

    rep(i,n) rep(j,n) {
        if(i!=j) {
            //cout<<i<<","<<j<<","<<W[i][j]<<endl;
            A[i][j] = ((W[i][j]+W[j][i]))/2.0;
            B[i][j] = W[i][j]-A[i][j];
            A[j][i] = A[i][j];
            B[j][i] = -B[i][j];
        }
        else {
            A[i][j]=W[i][j];
        }

    }

    rep(i,n) rep(j,n) {
        if(!j) cout<<A[i][j];
        else cout<<" "<<A[i][j];
        if(j==n-1) cout<<endl;
    }
    rep(i,n) rep(j,n) {
        if(!j) cout<<B[i][j];
        else cout<<" "<<B[i][j];
        if(j==n-1) cout<<endl;
    }

    return 0;
}


