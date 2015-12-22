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
int a[55];
int sum(int l,int r,bool f) {
    if(r<l) swap(l,r);
    int ret=0;
    for(int i=l;i<=r;i++) {
        if(f) {
            if((i-l+1)%2==0) ret+=a[i];
        }
        else {
            if((i-l+1)%2==1) ret+=a[i];
        }
    }

    return ret;
}
int get_aoki(int i) {
    int maxi=-INF;
    int ret=0;
    rep(j,N+1) if(j&&i!=j) {
        int t=sum(i,j,1);
        //cout<<"aoki "<<i<<", "<<j<<": "<<t<<endl;
        if(maxi<t) {
            maxi=t;
            ret=j;
        }
    }

    return ret;
}
int main() {
    cin>>N;
    rep(i,N) cin>>a[i+1];

    int ans=-INF;
    rep(i,N+1) if(i) {
        int l=get_aoki(i);
        ans=max(ans,sum(l,i,0));
        //cout<<i<<", "<<l<<": "<<sum(l,i,0)<<endl;
    }
    cout<<ans<<endl;

    return 0;
}

