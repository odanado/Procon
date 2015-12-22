#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
#include <cstdint>
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

int n;
string id;
int m;
vector<int> a;
vector<int> wcard;
int dp[20][20];

inline int f(int n) {
    if(n<10) return n;
    int ret = n%10;
    ret += n/10;
    return ret;
}
inline bool ok(string s) {
    int sum = 0;
    int cnt=1;
    for(int i=s.size()-1;i>=0;i--) {
        if(cnt%2==0) {
            sum+=f((s[i]-'0')*2);
        }
        else {
            sum+=s[i]-'0';
        }
        cnt++;
    }
    return sum%10==0;
}
int64_t dfs(string s,int depth,int sum) {
    if(depth == wcard.size()) return sum%10==0;
    if(dp[depth][sum%10]!=-1) return dp[depth][sum%10];
    int64_t ret = 0;

    rep(i,a.size()) {
        char c = s[wcard[depth]];
        s[wcard[depth]] = a[i]+'0';
        int t;
        if((id.size()-wcard[depth])%2==0) {
            t=f(a[i]*2);
        }
        else {
            t=a[i];
        }
        ret += dfs(s,depth+1,sum+t);
        s[wcard[depth]] = c;
    }
    return dp[depth][sum%10] = ret;

}
int fsum(string s) {
    int sum = 0;
    rep(i,s.size()) {
        if(s[i]=='*') continue;
        if((id.size()-i)%2==0) {
            sum+=f((s[i]-'0')*2);
        }
        else {
            sum+=s[i]-'0';
        }
    }
    return sum;
}
int main() {
    rep(i,20) rep(j,20) dp[i][j]=-1;
    cin>>n;
    cin>>id;
    cin>>m;
    a.resize(m);
    rep(i,m) cin>>a[i];
    rep(i,id.size()) if(id[i]=='*') wcard.pb(i);
    int sum = fsum(id);
    int64_t ans = dfs(id,0,sum);
    cout<<ans<<endl;
    return 0;
}
