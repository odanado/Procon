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

int bitCount(int S) {
    int ret=0;
    while(S) {
        if(S&1) ret++;
        S>>=1;
    }
    return ret;
}
int N,M,P,Q,R;
int x[400],y[400],z[400];
int main() {
    cin>>N>>M>>P>>Q>>R;
    rep(i,R) cin>>x[i]>>y[i]>>z[i];
    rep(i,R) x[i]--,y[i]--;
    int ans=0;
    rep(S,1<<N) {
        if(bitCount(S)!=P) continue;
        map<int,int> mp;
        rep(i,R) if(S>>x[i]&1) {
            mp[y[i]]+=z[i];
        }
        vector<int> vec;
        for(auto e:mp) vec.push_back(e.second);
        sort(all(vec));
        reverse(all(vec));
        int s=0;
        rep(i,min(Q,(int)vec.size())) s+=vec[i];
        ans=max(ans,s);
    }
    cout<<ans<<endl;
    return 0;
}

