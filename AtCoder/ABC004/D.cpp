#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
using ll = long long;

#define all(c) (c).begin(), (c).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

#define dp(i,j) dp[i+1000][j]
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int R, G, B;
int dp[2003][1003];

// 位置,置いた個数
int dfs(int pos, int sum) {
    if(pos==1000) {
        if (sum == R + G + B) return 0;
        else return INF;
    }
    if(dp(pos,sum)!=-1) return dp(pos,sum);
    int ret = INF;
    ret = dfs(pos + 1, sum);
    if (sum < R)
        ret = min(ret, dfs(pos + 1, sum + 1) + abs(-pos - 100));
    else if (sum < R + G)
        ret = min(ret, dfs(pos + 1, sum + 1) + abs(pos));
    else
        ret = min(ret, dfs(pos + 1, sum + 1) + abs(-pos + 100));
    return dp(pos,sum)=ret;
}

int main() {
    cin >> R >> G >> B;
    memset(dp,-1,sizeof(dp));
    cout<<dfs(-1000,0)<<endl;
    return 0;
}
