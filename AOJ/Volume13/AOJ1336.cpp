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

int N,L;
char d[22];
int p[22];

void solve() {
    rep(i,N) cin>>d[i]>>p[i];
    rep(i,N) {
        if(d[i]=='R') d[i]=1;
        else d[i]=-1;
    }
    int t=0;
    int ans;

    while(1) {
        rep(i,N) {
            p[i]+=d[i];
        }
        rep(i,N) rep(j,N) {
            if(j<=i) continue;
            if(p[i]==p[j]) {
                d[i]*=-1;
                d[j]*=-1;
            }
        }
        rep(i,N) if(p[i]==L) ans=i;
        rep(i,N) if(p[i]==0) ans=i;

        bool f=true;
        rep(i,N) f&=(p[i]>L || p[i]<0);
        if(f) break;

        t++;
    }
    cout<<t<<" "<<ans+1<<endl;
}

int main() {
    while(cin>>N>>L) {
        if(N+L==0) break;
        solve();
    }
    return 0;
}

