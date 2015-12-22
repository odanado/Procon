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
string s;
int dp[80001][11];

void solve() {
    memset(dp,0,sizeof(dp));
    if(s[0]!='0') {
        dp[0][s[0]-'0']++;
    }
    rep(i,s.size()) if(i) {
        rep(j,11) {
            dp[i][(j*10+s[i]-'0')%11]+=dp[i-1][j];
        }
        if(s[i]!='0') dp[i][s[i]-'0']++;
    }
    int ans=0;
    rep(i,s.size()) ans+=dp[i][0];
    cout<<ans<<endl;
}

int main() {
    while(cin>>s) {
        if(s=="0") break;
        solve();
    }

    return 0;
}

