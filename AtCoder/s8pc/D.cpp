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
const ll MOD=1000000007;
ll dp[1003][1003];

int H,W,K;
int X[202],Y[202];
vector<P> vec;

bool ok(int x,int y) {
    bool ret=false;
    rep(i,vec.size()-1) {
        int x1=vec[i].fr;
        int x2=vec[i+1].fr;
        int y1=vec[i].sc;
        int y2=vec[i+1].sc;
        x2++;
        y2++;
        ret |= x1<=x&&x<=x2 && y1<=y&&y<=y2;
    }

    return ret;
}

int main() {
    dp[0][0]=1;
    cin>>H>>W>>K;
    rep(i,K) cin>>X[i]>>Y[i];
    rep(i,K) X[i]--,Y[i]--;
    rep(i,K) {
        vec.pb(P(X[i],Y[i]));
    }
    vec.pb(P(0,0));
    vec.pb(P(H,W));
    sort(all(vec));
    rep(i,H) rep(j,W) {
        if(ok(i,j)) {
            //cout<<i<<", "<<j<<endl;
            dp[i+1][j]+=dp[i][j];
            dp[i+1][j]%=MOD;
            dp[i][j+1]+=dp[i][j];
            dp[i][j+1]%=MOD;
        }
    }
    cout<<dp[H-1][W-1]<<endl;
    return 0;
}

