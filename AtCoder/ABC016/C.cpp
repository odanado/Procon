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

template<class T>
bool chmin(T &a, const T &b) {
    if(a>b) {
        a=b;
        return true;
    }

    return false;
}

int N,M;
int d[11][11];
int main() {
    cin>>N>>M;
    rep(i,11) rep(j,11) d[i][j]=INF;
    rep(i,11) d[i][i]=0;
    rep(i,M) {
        int a,b;
        cin>>a>>b;
        a--,b--;
        d[a][b]=1;
        d[b][a]=1;
    }
    rep(k,N) rep(i,N) rep(j,N) {
        chmin(d[i][j],d[i][k]+d[k][j]);
    }
    rep(i,N) {
        int cnt=0;
        rep(j,N) if(i!=j) if(d[i][j]==2) cnt++;
        cout<<cnt<<endl;
    }
    return 0;
}

