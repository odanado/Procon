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
string ans;
void dfs(int S) {
    if(ans!="") return;
    if(__builtin_popcount(S)==4) return;
    if(__builtin_popcount(S)!=0&& __builtin_popcount(S)<=3) {
        vector<int> vec;
        rep(i,s.size()) if((S>>i)&1) vec.pb(s[i]-'0');
        //rep(i,vec.size()) cout<<vec[i]<<" ";
        //cout<<endl;
        int sum=0;
        int a=1;
        for(int i=vec.size()-1;i>=0;i--) {
            sum+=a*vec[i];
            a*=2;
        }
        if(sum%8==0) {
            rep(i,vec.size()) ans+=string(1,vec[i]+'0');
        }
    }
    rep(i,s.size()) {
        if((!(S>>i)&1)) dfs(S|1<<i);
    }
}
int main() {
    cin>>s;
    dfs(0);
    if(ans!="") {
        cout<<"YES"<<endl;
        cout<<ans<<endl;
    }
    else cout<<"NO"<<endl;
    return 0;
}

