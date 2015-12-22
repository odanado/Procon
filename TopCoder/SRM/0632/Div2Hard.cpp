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
const int MOD=1000000007;

class GoodSubset {
    vector<int> d;
    map<int,int> dp[101];
public:
    // 値xでt番目
    int dfs(int x,int t) {
        int ret = 0;
        if(dp[t].find(x)!=dp[t].end()) return dp[t][x];

        if(t==0) {
            if(x==1) return 1;
            else return 0;
        }

        if(x%d[t-1]==0) ret += dfs(x/d[t-1],t-1)%MOD;
        ret += dfs(x,t-1)%MOD;

        ret %= MOD;
        return dp[t][x]=ret;

    }
    int numberOfSubsets(int goodValue, vector <int> d) {
        this->d=d;

        return dfs(goodValue,d.size()) - ((goodValue==1));

    }

};
int main() {
    return 0;
}

