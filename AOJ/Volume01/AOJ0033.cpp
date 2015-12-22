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
int array[10];

bool dfs(int b,int c,int idx) {
    // cout<<b<<","<<c<<","<<idx<<endl;
    if(idx == 10) return true;

    int tb = array[idx] - b;
    int tc = array[idx] - c;

    if(tb<0 && tc<0) return false;

    bool ret = false;

    if(tb > 0) ret |= dfs(array[idx],c,idx+1);
    if(tc > 0) ret |= dfs(b,array[idx],idx+1);

    return ret;
}

void solve() {
    rep(i,10) cin>>array[i];

    string ans = "NO";
    if(dfs(0,0,0)) ans = "YES";
    cout<<ans<<endl;
}

int main() {
    cin>>n;
    rep(i,n) solve();
    return 0;
}

