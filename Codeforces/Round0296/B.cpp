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
typedef pair<char ,char > P;
typedef long long ll;

int n;
string s,t;
map<P,int> f;
int f2[26];
int main() {
    cin>>n;
    cin>>s>>t;
    swap(s,t);
    int ans=0;
    rep(i,n) {
        if(s[i]!=t[i]) {
            f[P(s[i],t[i])]=i;
            f2[s[i]-'a']=i+1;
            ans++;
        }
    }
    rep(i,n) {
        if(s[i]!=t[i] && f.count(P(t[i],s[i]))) {
            cout<<ans-2<<endl;
            cout<<i+1<<" "<<f[P(t[i],s[i])]+1<<endl;
            return 0;
        }
    }
    rep(i,n) {
        char c=t[i];
        if(s[i]!=t[i] && f2[c-'a']!=0) {
            cout<<ans-1<<endl;
            cout<<i+1<<" "<<f2[c-'a']<<endl;
            return 0;
        }
    }
    cout<<ans<<endl;
    cout<<"-1 -1"<<endl;
    return 0;
}

