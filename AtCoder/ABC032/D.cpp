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
#include <cassert>

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
using namespace std;
typedef pair<int ,int > P;
typedef long long ll;
const ll INF=1e18;

int N,W;
ll v[202],w[202];
inline ll solve1() {
    map<ll,ll> mp[2];
    vector<int> id[2];
    ll ret=0;
    rep(i,N) id[i%2].push_back(i);
    rep(i,2) {
        rep(j,1<<id[i].size()) {
            ll wsum=0,vsum=0;
            int idx=0;
            int S=j;
            while(S) {
                if(S&1) {
                    wsum+=w[id[i][idx]];
                    vsum+=v[id[i][idx]];
                }
                idx++;
                S>>=1;
            }

            auto t=mp[i][wsum];
            mp[i][wsum]=max(t,vsum);
        }
    }
    auto it=mp[1].begin();
    auto prev=it;
    it++;
    while(it!=mp[1].end()) {
        it->sc=max(it->sc,prev->sc);
        prev++;
        it++;
    }
    for(auto e:mp[0]) {
        ll t=W-e.fr;
        //printf("debug: %lld, %lld: %lld\n",e.fr,e.sc,t);
        if(t<0) continue;
        auto it=mp[1].upper_bound(t);
        if(it==mp[1].begin()) continue;
        it--;
        //printf("debug: %lld %lld\n",it->fr,it->sc);;
        assert(e.fr+it->fr<=W);
        ret=max(ret,e.sc+it->sc);
    }

    return ret;
}
ll dp2[200005];
inline ll solve2() {
    rep(i,N) for(int j=200004;j>=w[i];j--) {
        dp2[j]=max(dp2[j],dp2[j-w[i]]+v[i]);
    }
    int s=0;
    rep(i,N) s+=w[i];
    int t=min(W,s);
    return dp2[t];
}
ll dp3[202][202*1003+1];
ll solve3() {
    fill(dp3[0],dp3[0]+202*1003+1,INF);
    dp3[0][0]=0;
    rep(i,N) rep(j,202*1003) {
        if(j<v[i]) dp3[i+1][j]=dp3[i][j];
        else dp3[i+1][j]=min(dp3[i][j],dp3[i][j-v[i]]+w[i]);
    }
    int ret=0;
    rep(i,202*1003) {
        if(dp3[N][i]<=W) ret=max(ret,i);
    }

    return ret;
}
int main() {
    bool f2,f3;
    f2=f3=true;
    cin>>N>>W;
    rep(i,N) cin>>v[i]>>w[i];
    if(N<=30) {
        cout<<solve1()<<endl;
        return 0;
    }
    rep(i,N) {
        f3&=v[i]<=1000;
        f2&=w[i]<=1000;
    }
    if(f2) {
        cout<<solve2()<<endl;
        return 0;
    }
    if(f3) {
        cout<<solve3()<<endl;
        return 0;
    }
    return 0;
}

