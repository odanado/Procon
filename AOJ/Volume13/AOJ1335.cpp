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

int n,k,s;
int bitcount(int S) {
    int res=0;
    rep(i,n+2) if((S>>i)&1) res++;
    return res;
}
void solve() {
    ll ans=0;

    rep(i, 1<<(n)) {
        int sum=0;
        if(bitcount(i)!=k) continue;
        rep(j,(n+1)) {
            if(j==0) continue;
            if((i>>(j-1))&1) sum+=j;
        }

        if(sum==s) ans++;
    }

    cout<<ans<<endl;


}

int main() {
    while(cin>>n>>k>>s) {
        if(n+k+s==0) break;
        solve();
    }
    return 0;
}

