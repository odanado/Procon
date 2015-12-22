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
    ll ans=1e19;
    cin>>N>>H;
    cin>>A>>B>>C>>D>>E;

    rep(i,N+1) {
        ll t=H+B*i;
        ll lb=-1,ub=1e6;
        while(ub-lb>1) {
            //cout<<i<<": "<<lb<<", "<<ub<<endl;
            ll mid=(lb+ub)/2;
            ll j=mid;
            ll k=N-i-j;
            if(t+D*j-E*k>0) ub=mid;
            else lb=mid;
        }
        //printf("%d %d %d\n",i,lb,N-i-lb);
        ans=min(ans,A*i+C*ub);
    }
    cout<<ans<<endl;
    return 0;
}

