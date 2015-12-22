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
#include <tuple>

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
const ll INF=1e16;


struct Star{
    ll x,y,b;
    Star(ll x=0,ll y=0,ll b=0) :
        x(x),y(y),b(b){}
    bool operator<(const Star &rth) const {
        return std::tie(b,x,y)<std::tie(rth.b,rth.x,rth.y);
    }
};

struct SegTree {
    ll n;
    vector<ll> min_dat;
    vector<ll> max_dat;
    SegTree(ll N) {
        n=1;
        while(n<N) n*=2;
        min_dat.assign(1<<18,INF);
        max_dat.assign(1<<18,0);
    }

    void update(int k,ll a) {
        k+=n-1;
        min_dat[k]=a;
        max_dat[k]=a;
        while(k>0) {
            k=(k-1)/2;
            min_dat[k]=min(min_dat[k*2+1],min_dat[k*2+2]);
            max_dat[k]=max(max_dat[k*2+1],max_dat[k*2+2]);
        }
    }

    ll min_query(int a,int b,int k,int l,int r) {
        //printf("%d %d %d %d %d\n",a,b,k,l,r);
        if(r<=a||b<=l) return INF;

        if(a<=l&&r<=b) return min_dat[k];
        else {
            int vl=min_query(a,b,k*2+1,l,(l+r)/2);
            int vr=min_query(a,b,k*2+2,(l+r)/2,r);
            return min(vl,vr);
        }
    }

    ll max_query(int a,int b,int k,int l,int r) {
        //printf("%d %d %d %d %d\n",a,b,k,l,r);
        if(r<=a||b<=l) return 0;

        if(a<=l&&r<=b) return max_dat[k];
        else {
            int vl=max_query(a,b,k*2+1,l,(l+r)/2);
            int vr=max_query(a,b,k*2+2,(l+r)/2,r);
            return max(vl,vr);
        }
    }

    void dump() {
        rep(i,n) cout<<max_dat[i]<<" ";
        cout<<endl;
    }

};
int N,d;


vector<Star> stars;

int find(int x) {
    int l=0;
    int r=stars.size()-1;
    while(r-l>1) {
        int mid=(l+r)/2;
        if(stars[mid].b<x) l=mid;
        else r=mid;
    }
    return r;
}
int main() {
    cin>>N>>d;
    rep(i,N) {
        Star s;
        cin>>s.x>>s.y>>s.b;
        stars.pb(s);
    }
    SegTree segTreeX(N);
    SegTree segTreeY(N);

    sort(all(stars));

    rep(i,stars.size()) {
        // printf("%d %d %d %d\n",i,stars[i].x,stars[i].y,stars[i].b);
        segTreeX.update(i,stars[i].x);
        segTreeY.update(i,stars[i].y);
    }


    ll ans=0;
    int n=segTreeX.n;
    rep(i,stars.size()) {
        // int pos=find(stars[i].b+d);
        Star s=stars[i];
        s.b+=d;
        s.x=s.y=-INF;
        int pos=upper_bound(all(stars),s)-stars.begin();
        if(pos==i) continue;
        if(pos==N) pos--;
        ll tmp=0;
        tmp=segTreeX.max_query(i,pos+1,0,0,n)-segTreeX.min_query(i,pos+1,0,0,n);
        tmp*=segTreeY.max_query(i,pos+1,0,0,n)-segTreeY.min_query(i,pos+1,0,0,n);

        // cout<<i<<","<<stars[i].b+d<<","<<pos<<","<<tmp<<endl;
        ans = max(ans,tmp);

    }


    cout<<ans<<endl;
    return 0;
}

