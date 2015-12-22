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

int N,M;
vector<pair<int,P> > vec;
bool f[20004];

void solve() {
    rep(i,20004) f[i]=false;
    f[1]=true;
    vec.clear();

    rep(i,M) {
        int t,s,d;
        cin>>t>>s>>d;
        vec.pb(mp(t,mp(s,d)));
    }
    sort(all(vec));

    rep(i,vec.size()) {
        int t=vec[i].fr;
        int s=vec[i].sc.fr;
        int d=vec[i].sc.sc;
        if(f[s]) f[d]=true;
    }
    int ans=0;
    rep(i,20004) if(f[i]) ans++;
    cout<<ans<<endl;

}

int main() {
    while(cin>>N>>M) {
        if(N+M==0) break;
        solve();
    }
    return 0;
}

