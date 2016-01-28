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

ll solve(ll N) {
    vector<ll> vec;
    ll ret=0;
    vec.pb(25);
    rep(i,10) vec.pb(vec.back()*10+25);
    rep(i,N+1) if(i) {
        bool f=false;
        rep(j,vec.size()) if(i%vec[j]==0) f=true;
        if(252525<i&&f) cout<<i<<endl;
        ret+=f;
    }
    return ret;
}
ll N;
ll ans;
ll nico = 25;
int main() {
    cin>>N;
    ans=N/nico;
    /*
    vector<ll> vec2;
    rep(i,vec.size()) rep(j,vec.size()) if(i<j) if(vec[j]%vec[i]==0) vec2.pb(vec[j]/vec[i]);
    rep(i,vec2.size()) cout<<vec2[i]<<endl;
    rep(i,vec2.size()) ans-=N/vec2[i];
    */
    cout<<ans<<endl;
    //cout<<solve(N)<<endl;
    return 0;
}

