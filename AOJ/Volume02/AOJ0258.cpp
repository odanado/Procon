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
int h[102];

bool ok(vector<int> &vec) {
    int d = vec[0]-vec[1];
    rep(i,vec.size()) {
        if(i==0) continue;
        if(vec[i-1]-vec[i]!=d) return false;
    }

    return true;
}

void solve() {
    rep(i,n+1) cin>>h[i];

    rep(i,n+1) {
        vector<int> vec;
        rep(j,n+1) {
            if(i!=j) vec.pb(h[j]);
        }
        if(ok(vec)) {
            cout<<h[i]<<endl;
            break;
        }
    }

}

int main() {
    while(cin>>n) {
        if(n==0) break;
        solve();
    }

    return 0;
}

