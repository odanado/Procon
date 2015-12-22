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

ll lcm(ll a,ll b) {
    return a/__gcd(a,b)*b;
}
ll N,K;
const ll MOD=1000000007;

void func() {
    ll sum=0;
    for(ll i=1;i<=N;i++) {
        sum=(sum+lcm(i,K))%MOD;
    }
    cout<<sum<<endl;
}

int main() {
    cin>>N>>K;

    for(ll i=1;i<=N;i++) {
        printf("lcm(%lld,%lld)=%lld\n",i,K,lcm(i,K));

    }


    return 0;
}

