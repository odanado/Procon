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

int N;
string s1,s2;
map<char,int> cnvt;
int MCXI_to_int(string mcxi) {
    int a = 1;
    int ret = 0;
    rep(i,mcxi.size()) {
        if(isdigit(mcxi[i])) {
            a = mcxi[i]-'0';
        }
        else {
            ret += a * cnvt[mcxi[i]];
            a = 1;
        }
    }
    return ret;
}
string int_to_MCXI(int n) {
    string t = "mcxi";
    string ret = "";
    rep(i,t.size()) {
        int tmp=n/cnvt[t[i]];
        if(tmp==0) {
        }
        else if(tmp==1) {
            ret+=t[i];
        }
        else {
            ret+=('0'+tmp);
            ret+=t[i];
        }
        n %= cnvt[t[i]];
    }
    return ret;

}
void solve() {
    cin>>s1>>s2;
    cout<<int_to_MCXI(MCXI_to_int(s1)+MCXI_to_int(s2))<<endl;
    
}
int main() {
    cnvt['m']=1000;
    cnvt['c']=100;
    cnvt['x']=10;
    cnvt['i']=1;
    cin>>N;
    rep(i,N) {
        solve();
    }
    return 0;
}

