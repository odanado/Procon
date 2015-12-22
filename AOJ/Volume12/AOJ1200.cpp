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

int n;
const int MAX=(1<<15)+10;
bool is_prime[MAX];
void init() {
    rep(i,MAX) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<MAX;i++) if(is_prime[i]) {
        for(int j=i+i;j<MAX;j+=i) is_prime[j]=false;
    }
}
void solve() {
    int ans=0;
    rep(i,n) if(is_prime[i]) {
        if(is_prime[n-i]) {
            //cout<<i<<","<<n-i<<endl;
            if(i<=n-i) ans++;
        }
    }
    cout<<ans<<endl;
    
}
int main() {
    init();
    while(cin>>n) {
        if(!n) break;
        solve();
    }
    return 0;
}

