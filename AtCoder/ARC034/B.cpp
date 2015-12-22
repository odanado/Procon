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
ll f(ll x) {
    ll res=0;
    while(x) {
        res+=x%10;
        x/=10;
    }
    return res;
}

int main() {
    ll N;
    cin>>N;
    vector<ll> ans;
    for(ll i=max(1LL,N-200);i<N+200;i++) {
        if(i+f(i)==N) ans.pb(i);
    }

    cout<<ans.size()<<endl;
    rep(i,ans.size()) cout<<ans[i]<<endl;
    return 0;
}

