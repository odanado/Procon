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

bool isAbort;
int num(const string &s,int &idx) {
    if(isAbort) return 0;
    int ret=0;
    if(!isdigit(s[idx])) {
        isAbort=true;
        return 0;
    }
    if(idx==s.size()) {
        isAbort=true;
        return 0;
    }
    while(isdigit(s[idx])&&idx<s.size()) {
        ret*=10;
        ret+=s[idx]-'0';
        idx++;
    }
    return ret;
}
int expr(const string &s,int &idx) {
    int ret = num(s, idx);
    while(idx<s.size()) {
        if(isAbort) return 0;
        if(s[idx]=='+') {
            idx++;
            ret += num(s,idx);
        }
        else if(s[idx]=='-') {
            idx++;
            ret -= num(s,idx);
        }
    }

    return ret;
}
int main() {
    string s;
    int ans=-INF;
    cin>>s;
    s=s+s;
    rep(i,s.size()/2) {
        isAbort=false;
        int idx = 0;
        //cout<<s.substr(i,s.size()/2)<<endl;
        int t=expr(s.substr(i,s.size()/2),idx);
        if(!isAbort) {
            ans=max(ans,t);
        }
    }
    cout<<ans<<endl;
    return 0;
}

