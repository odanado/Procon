#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
 
using namespace std;
using ll = long long;
 
#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second
 
const ll INF=1e18;
const ll MOD=1e9+7;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
 
ll R,B;
ll x,y;
bool ok(ll k) {
    if(R-k<0) return false;
    if(B-k<0) return false;
    return (R-k)/(x-1)+(B-k)/(y-1)>=k;
}
int main() {
    cin>>R>>B;
    cin>>x>>y;
 
 
    ll ub=0,lb=1LL<<60;
    while(lb-ub>1) {
        ll mid=(ub+lb)/2;
        if(ok(mid)) ub=mid;
        else lb=mid;
    }
    cout<<ub<<endl;
 
    return 0;
}
