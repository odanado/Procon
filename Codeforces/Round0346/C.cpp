#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
using ll = long long;

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

const ll INF=1e9;
const ll MOD=1e9+7;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

// sum [l,r]
int calc(int l,int r) {
    if(r<=l) return 0;
    int n=r-l+1;
    return n*(2*l+(n-1))/2;
}
int n,m;
vector<int> a;
set<int> s;
int main() {
    cin>>n>>m;
    a.resize(n);
    rep(i,n) {
        cin>>a[i];
    }
    sort(all(a));
    rep(i,n) s.insert(a[i]);
    vector<int> ans;
    int b=1;
    while(m>0) {
        if(s.count(b)) {
            b++;
            continue;
        }
        if(m-b<0) break;
        ans.push_back(b);
        m-=b;
        b++;
    }
    cout<<ans.size()<<endl;
    rep(i,ans.size()) cout<<ans[i]<<(i+1==ans.size()?'\n':' ');


    return 0;
}

