#include <algorithm>
#include <functional>
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

ll pow(int a,int n) {
    if(n==0) return 1;
    ll ret=pow(a*a,n>>1);
    if(n&1) ret*=a;

    return ret;
}
ll f(int n) {
    int ret=0;
    while(n) {
        ret++;
        n/=10;
    }

    return ret;
}
int main() {
    ll n;
    cin>>n;

    ll d=f(n);
    ll a=pow(10,d)-1;
    ll tt=a/9;
    ll ans=(n+1)*d-tt;

    cout<<ans<<endl;
    return 0;
}

