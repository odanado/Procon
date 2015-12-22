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
ll dfs(ll sum,int p,int cnt) {
    if(sum==n) {
        return 1;
    }
    if(cnt==4) {
        return 0;
    }
    ll ret=0;
    for(ll i=p;i<=n;i++) {
        if(sum+i*i>n) break;
        ret+=dfs(sum+i*i,i,cnt+1);
    }

    return ret;
}
void solve() {
    cout<<dfs(0,1,0)<<endl;
}
int main() {
    while(cin>>n) {
        if(n==0) break;
        solve();
    }
    return 0;
}

