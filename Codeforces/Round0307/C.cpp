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

int n,m;
vector<int> a;

bool ok(ll time) {
    vector<int> b(a);
    int pos=n-1;
    rep(i,m) {
        while(pos>=0&&b[pos]==0) pos--;
        ll t=time-pos-1;
        if(t<0) return false;
        while(1) {
            if(t-b[pos]<0) {
                b[pos]-=t;
                break;
            };
            t-=b[pos];
            if(t<0) break;
            b[pos]=0;
            pos--;
            if(pos==-1) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    cin>>n>>m;
    a.resize(n);
    rep(i,n) cin>>a[i];
    ll l=0,r=1e18;
    while(r-l>1) {
        // cout<<l<<","<<r<<endl;
        ll mid=(l+r)/2;
        if(ok(mid)) r=mid;
        else l=mid;
    }
    cout<<r<<endl;
    return 0;
}

