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

class CartInSupermarketEasy {
public:
    int dp[102][102];
    int dfs(int n,int k) {
        if(n==0) return 0;
        if(dp[n][k] != -1) return dp[n][k];
        int &res = dp[n][k];
        res = dfs(n-1,k)+1;
        for(int x=1;x<n;x++) {
            for(int y=0;y<k;y++) {
                res = min(res,max(dfs(x,y),dfs(n-x,k-1-y))+1);
            }
        }
        return res;
    }
    int calc(int N, int K) {
        memset(dp,-1,sizeof(dp));
        return dfs(N,K);

    }
};

