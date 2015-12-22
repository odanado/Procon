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

ll n,k;
ll a[200005];

int main() {
    cin>>n>>k;
    rep(i,n) cin>>a[i];
    map<ll,ll> m1,m2;
    ll ans=0;

    rep(i,n) {
        if(a[i]%k==0) {
            ll t=a[i]/k;
            ans+=m2[t];
            m2[a[i]]+=m1[t];
        }
        m1[a[i]]++;
    }

    cout<<ans<<endl;

    return 0;
}

