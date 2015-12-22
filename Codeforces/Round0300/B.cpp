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

vector<int> quas;

int to_i(const string& s) {
    int ret;
    stringstream ss;
    ss<<s;
    ss>>ret;
    return ret;
}

void init(string s) {
    if(s.size() == 8) return;
    int t=to_i(s);
    if(t!=0) quas.pb(t);
    init(s+"0");
    init(s+"1");
}

int dp[1000006];

int main() {
    init("0");
    init("1");
    sort(all(quas));
    quas.erase(unique(all(quas)), quas.end());
    sort(all(quas),greater<int>());
    rep(i,1000006) dp[i]=INF;
    dp[0]=0;
    rep(i,quas.size()) if(1000006>quas[i]) dp[quas[i]]=1;
    rep(i,1000006) rep(j,quas.size()) {
        if(i+quas[j]<1000006) dp[i+quas[j]] = min(dp[i]+1,dp[i+quas[j]]);
    }
    int n;
    cin>>n;
    int cnt=dp[n];
    // rep(i,n+1) cout<<i<<" : "<<dp[i]<<endl;
    vector<int> ans;

    while(cnt) {
        rep(j,quas.size()) {
            int t=n-quas[j];
            if(0<=t&&t<1000006 && dp[t]==cnt-1) {
                ans.pb(quas[j]);
                n=t;
                cnt--;
            }
        }
    }

    cout<<ans.size()<<endl;
    rep(i,ans.size()) {
        printf("%d%c",ans[i],i+1==ans.size()?'\n':' ');
    }
    return 0;
}

