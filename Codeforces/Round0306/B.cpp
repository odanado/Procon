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

int n,l,r,x;
int c[20];

int get_max(int S) {
    int ret=0;
    int i=0;
    while(S) {
        if(S&1) ret=max(ret,c[i]);
        S>>=1;
        i++;
    }

    return ret;
}
int get_min(int S) {
    int i=0;
    int ret=INF;
    while(S) {
        if(S&1) ret=min(ret,c[i]);;
        S>>=1;
        i++;
    }

    return ret;
}
int get_sum(int S) {
    int ret=0;
    int i=0;
    while(S) {
        if(S&1) ret+=c[i];
        S>>=1;
        i++;
    }

    return ret;
}

int main() {
    cin>>n>>l>>r>>x;
    int ans=0;
    rep(i,n) cin>>c[i];

    rep(S,1<<n) {
        if(__builtin_popcount(S)<=1) continue;
        int mini=get_min(S);
        int maxi=get_max(S);
        int sum=get_sum(S);
        if(!(l<=sum&&sum<=r)) continue;
        if(maxi-mini<x) continue;
        ans++;
    }

    cout<<ans<<endl;
    return 0;
}

