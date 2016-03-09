#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(e) (e).begin(), (e).end()
typedef long long ll;
ll n;
vector<ll> tubo28;
 
void make(ll m,int digit) {
    if(m) tubo28.push_back(m);
    if(digit==5) {
        return;
    }
    make(m*10+2,digit+1);
    make(m*10+8,digit+1);
}
bool ok(vector<ll> &vec,ll m) {
    ll t=m;
    rep(i,vec.size()) {
        if(vec[i]==t) continue;
        while(m%vec[i]==0) m/=vec[i];
    }
 
    return m==1;
}
vector<ll> vec;
ll dfs(int idx,ll n) {
    if(n==1) {
        return 0;
    }
    if(idx==tubo28.size()) return -1;
    ll ret=-1;
 
    ret=max(ret,dfs(idx+1,n));
    if(n%tubo28[idx]==0) {
        ll t=dfs(idx,n/tubo28[idx]);
        if(t>=0) ret=max(ret,t+1);
    }
     
    return ret;
}

bool ok(ll m) {
    while(m) {
        if(m%10!=2&&m%10!=8) return false;
        m/=10;
    }

    return true;
}
 
int main() {
    make(0,0);
    sort(all(tubo28));
    cin>>n;
    ll ans=dfs(0,n);
    if(n==1) ans=-1;
    if(ans==-1&&ok(n)) {
        ans=1;
    }
    cout<<ans<<endl;
    return 0;
}
