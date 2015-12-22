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
#define rep(i,n) for(long long i=0;i<(n);i++)
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

string A;
ll N;
ll B;
ll ans = INF;
ll dp[20][1<<11];
ll bitcnt(ll S) {
    ll ret = 0;
    rep(i,10) if((S>>i)&1) ret++;
    return ret;
}
ll dfs(ll pos,ll S) {
    ll ret = 10e16;
    if(pos+1==A.size()) {
     //cout<<pos<<","<<S<<endl;

        return 0;
    }
    if(dp[pos][S]!=-1) return dp[pos][S];
    int r = A.size() - pos - 1;
    ll tmp = pow(10,r);
    if(B>=bitcnt(S)) {
        rep(i,10) {
            if((S>>i)&1) {
                ll t = dfs(pos+1,S)+i*tmp;
                ret=min(ret,abs(N-t));
            }
            else {
                ll t = dfs(pos+1,S|(1<<i))+i*tmp;
                ret=min(ret,abs(N-t));
            }
        }
    }
    else {
        rep(i,10) if((S>>i)&1) {
            ll t = dfs(pos+1,S)+i*tmp;
            ret=min(ret,abs(N-t));
        }

    }
    return dp[pos][S]=ret;

}
ll cnv(string s) {
    stringstream ss;
    ll ret=0;
    ss<<s;
    ss>>ret;
    return ret;
}

int main() {
    rep(i,20) rep(j,1<<11) dp[i][j]=-1;
    cin>>A>>B;
    N = cnv(A);
    cout<<dfs(0,0)<<endl;
    return 0;
}

