#include<iostream>

#define rep(i,n) for(int i=0;i<(n);i++)
#define max(a,b) a>b?a:b;
using namespace std;

int d[401][401];
const int INF = 100000000;

int main() {
    rep(i,400) rep(j,400) d[i][j]=-INF;
    rep(i,400) d[i][i]=0;
    int n,m;
    cin>>n>>m;
    rep(i,m) {
        int a,b,c;
        cin>>a>>b>>c;
        d[a][b]=c;
    }
    rep(k,n) rep(i,n) rep(j,n) d[i][j] = max(d[i][j],d[i][k]+d[k][j]);

    cout<<d[0][n-1]<<endl;
    
    return 0;
}

/* 2014/05/22 AC */
