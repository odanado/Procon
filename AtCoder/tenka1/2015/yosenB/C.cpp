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
#define rep(i,n) for(long long i=0;i<(n);i++)
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

const int MOD=1000000007;
ll L;

int main() {
    ll ans=0;
    cin>>L;

    rep(c,L/2+1) if(c) {
        for(ll a=(c-1)/2;a<=(L-c-1)/2;a++) {
            ll b=a+1;
            if(a<b&&b<c&&a+b>c) {
                //printf("%d %d %d\n",a,b,c);
                ans++;
            }
        }
    }

    cout<<ans<<endl;
    return 0;
}

