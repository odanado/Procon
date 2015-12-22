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

int N,M;
int d[301][301];
int main() {
    rep(i,301) rep(j,301) d[i][j]=INF;
    rep(i,301) d[i][i]=0;
    cin>>N>>M;
    rep(i,M) {
        int a,b,t;
        cin>>a>>b>>t;
        a--,b--;
        d[a][b]=t;
        d[b][a]=t;
    }

    rep(k,301) rep(i,301) rep(j,301) d[i][j] = min(d[i][j], d[i][k]+d[k][j]);

    int ans = INF;
    rep(i,N) {
        int t=0;
        rep(j,N) if(i!=j) t=max(t,d[i][j]);
        ans=min(t,ans);
    }

    cout<<ans<<endl;

    return 0;
}

