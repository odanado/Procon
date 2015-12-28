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

int N;
ll a[200005];
int f1() {
    int maxi=0;
    int s=0,t=0;
    while(s<N) {
        if(a[s]!=0) {
            break;
        }
        s++;
        t++;
    }
    //printf("%d %d\n",s,t);
    while(s<N) {
        while(t<N) {
            if(a[t]==0) break;
            t++;
        }
        //printf("%d %d\n",s,t);
        maxi=max(maxi,t-s);
        t++;
        s=t;
    }
    return maxi;
}
int f2() {
    int ret=0;
    int s=0;
    int t=N-1;
    while(s<N) {
        if(a[s]==0) break;
        s++;
    }
    s--;
    while(t>=0) {
        if(a[t]==0) break;
        t--;
    }
    t++;
    if(t==N) return 0;
    //printf("%d %d\n",s,t);
    ret += s;
    ret += N + 1 - t;
    return ret;
}
int main() {
    cin>>N;
    rep(i,N) cin>>a[i];
    ll ans=0;
    bool f=false;
    ll x = * min_element(a,a+N);
    ans = x * N;
    rep(i,N) a[i]-=x;
    ans+=max(f1(),f2());
    cout<<ans<<endl;
    return 0;
}

