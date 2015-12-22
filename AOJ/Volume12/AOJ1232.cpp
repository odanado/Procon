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

ll m,a,b;
vector<int> prime;
bool is_prime[100005];

void solve() {
    P ans;
    ll maxi = 0;
    rep(i,prime.size()) for(int j=i;j<prime.size();j++) {
        ll p=prime[i];
        ll q=prime[j];
        if(m < p*q) break;
        if(m >= p*q && 1.0*a/b <= 1.0*p/q && 1.0*p/q <= 1.0) {
            if(maxi < p*q) {
                ans = P(p,q);
                maxi=p*q;
            }
        }
    }
    cout<<ans.fr<<" "<<ans.sc<<endl;


}

void init() {
    rep(i,100005) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<100005;i++) {
        if(is_prime[i]) for(int j=i+i;j<100005;j+=i) is_prime[j]=false;
    }

    rep(i,100005) if(is_prime[i]) prime.pb(i);
}

int main() {
    init();
    while(cin>>m>>a>>b) {
        if(m+a+b==0) break;
        solve();
    }
    return 0;
}

