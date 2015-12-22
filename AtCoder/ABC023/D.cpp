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

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
using namespace std;
typedef pair<int ,int > P;
typedef long long ll;
const ll INF=1e18;

int N;
ll H[100005],S[100005];

bool ok(ll x) {
    vector<ll> vec;
    rep(i,N) if(H[i]>x) return false;
    rep(i,N) vec.pb((x-H[i])/S[i]);

    sort(all(vec));
    rep(i,N) {
        if(i>vec[i]) return false;
        //cout<<x<<": "<<i<<", "<<vec[i]<<endl;
    }
    return true;
}

int main() {
    cin>>N;
    rep(i,N) {
        cin>>H[i]>>S[i];
    }
    ll lb=0,ub=INF;
    while(ub-lb>1) {
        ll mid=(lb+ub)/2;
        if(ok(mid)) {
            ub=mid;
        }
        else lb=mid;
    }
    cout<<ub<<endl;
    return 0;
}

