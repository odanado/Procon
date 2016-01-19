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

const int INF=1e18;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
using namespace std;
typedef pair<int ,int > P;
typedef long long ll;
int N,M;
ll L;
ll D[5*10004];
ll diff[5*10004];

bool ok(ll d) {
    //cout<<"d = "<<d<<endl;
    ll cnt=0;
    ll sum=0;
    rep(i,N+1) {
        sum+=diff[i];
        //cout<<"sum = "<<sum<<endl;
        if(sum>=d) {
            sum=0;
        }
        else {
            cnt++;
        }
    }
    //cout<<"cnt = "<<cnt<<endl;
    return cnt<=M;
}

int main() {
    scanf("%lld %d %d\n",&L,&N,&M);
    rep(i,N) scanf("%lld",D+i);
    sort(D,D+N);
    D[N]=L;
    rep(i,N) diff[i+1]=D[i+1]-D[i];
    diff[0]=D[0];
    ll lb=-1,ub=INF;
    while(ub-lb>1) {
        ll mid=(ub+lb)/2;
        //cout<<lb<<", "<<ub<<endl;
        if(ok(mid)) lb=mid;
        else ub=mid;
    }
    printf("%lld\n",lb);
    return 0;
}

