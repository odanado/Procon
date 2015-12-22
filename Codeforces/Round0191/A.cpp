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
int n;
int a[102];

void flip(int l,int r) {
    for(int i=l;i<r;i++) a[i]^=1;
}
int sum() {
    int res=0;
    rep(i,n) res+=a[i];
    return res;
}

int main() {
    cin>>n;
    rep(i,n) cin>>a[i];
    int ans=0;

    rep(i,n) rep(j,n+1) if(i<j) {
        flip(i,j);
        ans=max(ans,sum());
        flip(i,j);
    }

    cout<<ans<<endl;
    return 0;
}

