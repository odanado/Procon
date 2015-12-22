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

void solve(int N) {
    ll ans=0;
    rep(i,N+1) if(i) {
        int m=i;
        while(m) {
            if(m%10==1) ans++;
            m/=10;
        }
    }
    cout<<ans<<endl;
}

int cnt(int N) {
    int ret=0;
    while(N) {
        if(N%10==1) ret++;
        N/=10;
    }
    return ret;
}

ll f(int n,int d) {
    ll m=n/pow(10,d);
    ll t=n-m*pow(10,d);
    t*=cnt(m);

    if(m%10!=1) t+=pow(10,d-1);
    else t*=2;

    return t;
}


int main() {
    int N;
    cin>>N;
    solve(N);
    /*
    rep(i,N+1) if(i) {
        if(i%10==9) {
        cout<<i<<": ";
        solve(i);
        }
    }
    solve(N);
    */


    return 0;
}

