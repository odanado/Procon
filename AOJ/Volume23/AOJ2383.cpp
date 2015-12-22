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

const ll MOD=1000000007;
ll N,T;
ll D[100005];
int main() {

    cin>>N>>T;
    rep(i,N) cin>>D[i];
    sort(D,D+N);
    ll ans=1;
    rep(i,N) {
        ll pos=upper_bound(D,D+N,D[i]+T)-D;
        //printf("%d %d : %d\n",i,pos,pos-i);
        ans=ans*(pos-i)%MOD;
    }


    cout<<ans%MOD<<endl;
    return 0;
}

