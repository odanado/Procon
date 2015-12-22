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
int v1,v2;
int t,d;

int f2() {
    int v=v1;
    int s=0;
    int a[110]={};
    a[t]=v2;
    for(int i=t-1;i>=0;i--) a[i]+=a[i+1]+d;
    rep(i,t+1) {
        if(!i) continue;
        s+=v;
        v=min(a[i+1],v+d);
    }
    return s;
}


int main() {
    int s=0;
    cin>>v1>>v2;
    cin>>t>>d;
    int ans=f2();
    rep(i,t-1) {
        s+=v1;
        v1=min(v1+d,v2+d);
    }
    s+=v2;
    ans=max(ans,s);
    cout<<ans<<endl;
    return 0;
}

