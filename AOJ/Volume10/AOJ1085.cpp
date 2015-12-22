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

int n,S;
int r[10004];
void solve() {
    int ans=0;
    rep(i,n) cin>>r[i];
    sort(r,r+n);

    rep(i,n) {
        int pos=upper_bound(r+i+1,r+n,S-r[i])-r;
        // cout<<r[i]<<","<<pos<<endl;
        ans+=n-pos;
    }

    cout<<ans<<endl;

}

int main() {
    while(cin>>n>>S) {
        if(n+S==0) break;
        solve();
    }
    return 0;
}

