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
typedef long long ll;
typedef pair<ll ,ll > P;

int N;
ll sec[1003];
char type[1003];
string id[1003];

ll cross(P p1,P p2) {
    int m1=max(p1.fr,p2.fr);
    int m2=min(p1.sc,p2.sc);

    return max(0,m2-m1);
}

void solve() {
    map<string,vector<P>> seg;
    set<string> visitors;
    rep(i,N) {
        if(id[i]!="000") visitors.insert(id[i]);
        if(type[i]=='I') {
            seg[id[i]].pb(P(sec[i],1e18));
        }
        else {
            auto it=seg[id[i]].end();
            it--;
            it->second=sec[i];
        }
    }

    map<string,ll> times;
    for(auto visitor : visitors) {
        for(const auto &e1 : seg["000"]) for(const auto &e2 : seg[visitor]) {
            //printf("[%s] %lld %lld -> %lld %lld : %lld\n",visitor.c_str(), e1.fr,e1.sc,e2.fr,e2.sc,cross(e1,e2));
            times[visitor]+=cross(e1,e2);
        }
    }

    ll ans=0;
    for(auto visitor : visitors) ans=max(ans,times[visitor]);
    cout<<ans/60<<endl;


}

int main() {
    while(cin>>N) {
        if(N==0) break;
        rep(i,N) {
            int M,D,h,m;
            scanf("%d/%d %d:%d",&M,&D,&h,&m);
            sec[i]=2678400*M+86400*D+3600*h+60*m;
            cin>>type[i];
            cin>>id[i];
        }
        solve();
    }
    return 0;
}

