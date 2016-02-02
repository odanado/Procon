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
int x[200005],y[200005];
map<P,int> cnt;
int main() {
    cin>>n;
    rep(i,n) cin>>x[i]>>y[i];
    rep(i,n) {
        int t=y[i]-x[i];
        cnt[P(t,1)]++;
        t=y[i]+x[i];
        cnt[P(t,-1)]++;
    }
    ll ans=0;
    for(auto e:cnt) {
        //cout<<e.fr.fr<<", "<<e.fr.sc<<"-> "<<e.sc<<endl;
        int t=e.sc;
        ans+=t*(t-1)/2;
    }
    cout<<ans<<endl;
    return 0;
}

