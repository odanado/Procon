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

vector<int> prime;
bool is_prime[1000006];
void init() {
    rep(i,1000006) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<1000006;i++) {
        if(is_prime[i]) {
            prime.pb(i);
            for(int j=i+i;j<1000006;j+=i) is_prime[j]=false;
        }
    }
}
int a,d,n;
void solve() {
    int m = 0;
    int cnt = 0;
    while(1) {
        if(is_prime[a+d*m]) cnt++;
        if(n==cnt) break;
        m++;
    }
    cout<<a+d*m<<endl;
    
}
int main() {
    init();
    while(cin>>a>>d>>n) {
        if(a+d+n==0) return 0;
        solve();
    }
    
    return 0;
}

