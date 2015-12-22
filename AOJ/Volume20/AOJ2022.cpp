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

int n;

string merge(const string &s1, const string &s2) {
    string ret;
    rep(i,min(s1.size(),s2.size())+1) {
        string t1(s1.substr(s1.size()-i,i));
        string t2(s2.substr(0,i));
        if(t1==t2) {
            ret = s1.substr(0,s1.size()-i);
            ret += t1;
            ret += s2.substr(i,s2.size()-i);
        }
    }

    return ret;
}

bool is_substr(const string &s1, const string &s2) {
    if(s1.size()>s2.size()) return false;
    if(s2.find(s1)==string::npos) return false;
    return true;
}

vector<string> comp(const vector<string> &vec) {
    vector<string> ret;

    rep(i,vec.size()) {
        bool ok=true;
        rep(j,vec.size()) if(i!=j) {
            ok&=!is_substr(vec[i],vec[j]);
        }
        if(ok) ret.pb(vec[i]);
    }

    return ret;
}

bool chmin(string &a, const string &b) {
    if(a.size()>b.size() || (a.size()==b.size()&&a>b)) {
        a=b;
        return true;
    }
    return false;
}

string dp[11][1<<11];

void solve() {
    rep(i,11) rep(j,1<<11) dp[i][j]=string(110,'z');

    vector<string> vec(n);
    rep(i,n) cin>>vec[i];
    vec = vector<string>(comp(vec));
    sort(all(vec));
    vec.erase(unique(all(vec)),vec.end());

    rep(i,vec.size()) dp[i][1<<i]=vec[i];
    rep(i,vec.size()) rep(S,1<<vec.size()) {
        if(!((S>>i)&1)) continue;
        rep(j,vec.size()) {
            if((S>>j)&1) continue;
            //cout<<dp[i][S]<<","<<vec[j]<<" : "<<merge(dp[i][S],vec[j])<<endl;
            chmin(dp[j][S|(1<<j)],merge(dp[i][S],vec[j]));
        }
    }

    string ans=dp[0][(1<<vec.size())-1];
    rep(i,vec.size()) if(i) chmin(ans,dp[i][(1<<vec.size())-1]);
    cout<<ans<<endl;

}
int main() {
    while(cin>>n) {
        if(n==0) break;
        solve();
    }
    return 0;
}

