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

int b,r,g,c,s,t;

void solve() {
    int ans = 100;
    t-=s;
    ans += c*2;
    ans += g*7;
    ans -= t*3;
    ans += r*3*16;
    ans += b*5*16;
    ans += r*15;
    ans += b*15;
    cout<<ans<<endl;

}

int main() {
    while(cin>>b>>r>>g>>c>>s>>t) {
        if(b+r+g+c+s+t==0) break;
        solve();
    }
    return 0;
}

