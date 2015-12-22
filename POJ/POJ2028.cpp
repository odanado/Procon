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

int N,Q;
void solve() {
    int a[102]={};
    rep(i,N) {
        int m;
        cin>>m;
        rep(i,m) {
            int t;
            cin>>t;
            a[t]++;
        }
    }
    int ans = 0;
    for(int i=N;i>=Q;i--) {
        rep(j,102) {
            if(a[j]>=i) {
                cout<<j<<endl;
                return;
            }
        }
    }
    cout<<"0"<<endl;
}
int main() {
    while(cin>>N>>Q) {
        if(N+Q==0) return 0;
        solve();
    }
    return 0;
}

