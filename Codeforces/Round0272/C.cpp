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

ll a,b;
const ll MOD = 1000000007;
int main() {
    cin>>a>>b;
    ll ans = 0;

    ans = (a*(a+1)/2) % MOD;
    ans = ans * b % MOD;
    ans += a;
    ans %= MOD;

    ans = ans * ((b*(b-1)/2)%MOD);
    ans %= MOD;
    cout<<ans<<endl;
    return 0;
}

