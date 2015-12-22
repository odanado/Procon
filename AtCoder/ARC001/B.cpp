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

int A,B;
int ary[] = {1,5,10};
map<int,int> dp;
int main() {
    rep(i,100) dp[i]=INF;
    cin>>A>>B;
    dp[A]=0;
    rep(i,100) {
        rep(j,3) {
            dp[i+ary[j]] = min(dp[i+ary[j]],dp[i]+1);
            dp[i-ary[j]] = min(dp[i-ary[j]],dp[i]+1);
        }
    }
    rep(i,100) {
        rep(j,3) {
            dp[i+ary[j]] = min(dp[i+ary[j]],dp[i]+1);
            dp[i-ary[j]] = min(dp[i-ary[j]],dp[i]+1);
        }
    }
    rep(i,100) {
        rep(j,3) {
            dp[i+ary[j]] = min(dp[i+ary[j]],dp[i]+1);
            dp[i-ary[j]] = min(dp[i-ary[j]],dp[i]+1);
        }
    }
    rep(i,100) {
        rep(j,3) {
            dp[i+ary[j]] = min(dp[i+ary[j]],dp[i]+1);
            dp[i-ary[j]] = min(dp[i-ary[j]],dp[i]+1);
        }
    }
    rep(i,100) {
        rep(j,3) {
            dp[i+ary[j]] = min(dp[i+ary[j]],dp[i]+1);
            dp[i-ary[j]] = min(dp[i-ary[j]],dp[i]+1);
        }
    }
    cout<<dp[B]<<endl;
    return 0;
}

