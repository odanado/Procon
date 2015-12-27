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

const int MOD = 1000003;
ll mod_pow(ll a,int n) {
    ll ret=1;
    while(n) {
        if(n&1) {
            ret*=a;
            ret%=MOD;
        }
        a*=a;
        a%=MOD;
        n>>=1;
    }
    return ret;
}
int x,N;
int main() {
    ll ans=0;
    cin>>x>>N;
    rep(i,N) {
        int a;
        cin>>a;
        ans+=mod_pow(x,a);
        ans%=MOD;
    }
    cout<<ans<<endl;
    return 0;
}

