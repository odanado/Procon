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

ll s;
ll pow(ll a,ll n) {
    if(n==0) return a;
    if(n&1) a*=a;
    return pow(a,n>>1);
}

ll f(ll x) {
    return (x+1) * ((ll)(log10(10*x)))-(pow(10,(ll)(log10(10*x)))-1)/9;
}

ll C(ll x) {
    ll res=0;
    ll a=1;
    ll keta=1;
    while(a<=x) {
        ll t=min(a*10-1,x);
        ll t1=(t)/3-(a-1)/3;
        ll t2=(t)/5-(a-1)/5;
        ll t3=(t)/15-(a-1)/15;
        res+=((t)-a+1-t1-t2+t3)*keta;
        res+=(t1+t2)*4;

        a*=10;
        keta++;
    }
    return res;
}

string to_s(ll x) {
    stringstream ss;
    ss<<x;
    string res;
    ss>>res;
    return res;
}

int main() {
    cin>>s;
    ll lb=0,ub=1e18+7;
    while(ub-lb>1) {
        ll mid = (ub+lb)/2;
        if(C(mid)>=s) ub=mid;
        else lb=mid;
    }
    string ans="";
    for(ll i=ub;i<ub+10;i++) {
        string tmp=to_s(i);
        if(i%3==0) ans+="Fizz";
        if(i%5==0) ans+="Buzz";
        if(i%3!=0&&i%5!=0) ans+=tmp;
        if(ans.size()>30) break;
    }
    ll a=s-C(lb)-1;
    for(ll i=a;i<a+20;i++) cout<<ans[i];
    cout<<endl;

    return 0;
}

