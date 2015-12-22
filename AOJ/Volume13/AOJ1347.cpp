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

void add(vector<P> &segs,int a,int b) {
    if(b<a) swap(a,b);
    bool f=true;
    rep(i,segs.size()) {
        if(!((b<segs[i].fr)||(segs[i].sc<a))) {
            segs[i].fr=min(segs[i].fr,a);
            segs[i].sc=max(segs[i].sc,b);
            f=false;
        }
    }
    if(f) segs.pb(P(a,b));
}
int N,m;


int main() {
    vector<P> segs,in;
    cin>>N>>m;
    rep(i,m) {
        int c,d;
        cin>>c>>d;
        in.pb(P(c,d));
    }
    sort(all(in));
    ll ans=0;
    rep(i,m) {
        add(segs,in[i].fr,in[i].sc);
    }

    rep(i,segs.size()) {
        //printf("%d %d\n",segs[i].fr,segs[i].sc);
        ans+=(segs[i].sc-segs[i].fr)*2;
    }
    ans+=N+1;
    cout<<ans<<endl;
    return 0;
}

