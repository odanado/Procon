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

int N,M;
int l[1000006],r[1000006],s[1000006];
ll sum[1000006];
ll f(int a) {
    return sum[a];
}
int main() {
    cin>>N>>M;
    ll ans=0;
    ll b=0;
    rep(i,N) cin>>l[i]>>r[i]>>s[i];
    rep(i,N) l[i]--;
    rep(i,N) {
        ll t=s[i];
        sum[l[i]]+=t;
        sum[r[i]]-=t;
        b+=s[i];
    }
    rep(i,1000006) if(i) sum[i]+=sum[i-1];
    //rep(i,M) cout<<i<<": "<<sum[i]<<endl;
    rep(i,M) ans=max(ans,b-f(i));
    cout<<ans<<endl;

    return 0;
}

