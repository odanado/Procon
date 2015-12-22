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

ll N,H;
ll A,B,C,D,E;
int main() {
    cin>>N>>H;
    cin>>A>>B>>C>>D>>E;

    ll s=0;
    s=H-E*N;
    if(s>0) {
        cout<<"0"<<endl;
        return 0;
    }
    ll ans=1e18;

    B+=E;
    D+=E;

    rep(i,N+1) {
        ll t=((-s-i*B)/D)+1;
        //printf("[%d: %lld %lld = %lld]\n",i,-s-i*B,D,t);
        t=max(0LL,t);
        if(-s-i*B<0) t=0;
        ans=min(ans,i*A+t*C);
    }
    cout<<ans<<endl;

    return 0;
}

