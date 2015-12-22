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
int n,d;
int gem[30004];
int dp[30004][500];
const int offset = 250;

int dfs(int pos,int a) {
    // cout<<pos<<","<<a<<endl;
    if(pos > 30001) return 0;
    int b = a + offset - d;
    // cout<<pos<<","<<a<<","<<b<<endl;
    if(dp[pos][b] != -1) return dp[pos][b];

    int res = 0;
    if(a==1) {
        res = gem[pos] + max(dfs(pos+a,a),dfs(pos+a+1,a+1));
    }
    else {
        res = gem[pos] + max(dfs(pos+a,a),max(dfs(pos+a+1,a+1),dfs(pos+a-1,a-1)));
    }

    dp[pos][b] = (res);
    return res;
}

int main() {
    memset(dp,-1,sizeof(dp));
    rep(i,30004) gem[i]=0;
    cin>>n>>d;
    int a;
    rep(i,n) {
        cin>>a;
        gem[a]++;
    }
    cout<<dfs(d,d)<<endl;
    return 0;
}

