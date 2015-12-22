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


int x,y,z;

    //マス目,金額(50*100<6000)
    double dp[57][6000];
int solve() {
    int r[5];
    P event[57];
    rep(i,57) rep(j,6000) dp[i][j]=0.0;
    rep(i,x) cin>>r[i];
    rep(i,z) {
        int n,e,a;
        cin>>n>>e>>a;
        event[n]=P(e,a);
    }

    dp[0][0] = 1.0;

    rep(i,y) rep(j,6000) rep(k,x) {
        //dp[i][j] が event を利用して 確率1/xで遷移する?

        int tx = min(i+r[k],y);
        P p = event[tx];
        if(p.first==1) {
            dp[min(y,tx+p.sc)][j] += dp[i][j] * (1.0/x);
        }
        else if(p.first==2) {
            dp[tx][j+p.sc] += dp[i][j] * (1.0/x);
        }
        else {
            dp[tx][max(0,j-p.sc)] += dp[i][j] * (1.0/x);

        }

    }

    double ans=0.0;
    rep(i,6000) {
        ans += dp[y][i]*i;
    }
    return (int) ans;



}

int main()
{
    while(cin>>x>>y>>z) {
        if(x+y+z==0) return 0;
        cout<<solve()<<endl;
    }
    return 0;
}


