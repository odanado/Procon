#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
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

const ll INF=1e9;
const ll MOD=1e9+7;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int N,Q;
int a[200005];
int main() {
    cin>>N>>Q;
    rep(i,Q) {
        int l,r;
        cin>>l>>r;
        a[l]++;
        a[r+1]--;
    }
    rep(i,200005) if(i) a[i]+=a[i-1];
    rep(i,N+1) if(i) cout<<a[i]%2;
    cout<<endl;
    return 0;
}

