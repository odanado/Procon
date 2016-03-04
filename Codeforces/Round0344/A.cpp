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

ll f(ll *a,int l,int r) {
    ll ret=0;
    for(int i=l;i<=r;i++) ret|=a[i];
    return ret;
}
int n;
ll a[1003],b[1003];

int main() {
    ll ans=0;
    cin>>n;
    rep(i,n) cin>>a[i];
    rep(i,n) cin>>b[i];
    rep(l,n) rep(r,n) if(l<=r) {
        ans=max(ans,f(a,l,r)+f(b,l,r));
    }
    cout<<ans<<endl;
    return 0;
}

