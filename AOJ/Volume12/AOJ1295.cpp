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

int w,d;

void solve() {
    ll ans=0;
    int a1[50]={};
    int a2[50]={};
    set<int> S;
    rep(i,w) {
        int b;
        cin>>b;
        S.insert(b);
        a1[b]++;
    }
    rep(i,d) {
        int b;
        cin>>b;
        S.insert(b);
        a2[b]++;
    }

    for(auto e : S) {
        ans += max(a1[e],a2[e])*e;
    }
    cout<<ans<<endl;
}

int main() {
    while(cin>>w>>d) {
        if(w+d==0) break;
        solve();
    }
    return 0;
}

