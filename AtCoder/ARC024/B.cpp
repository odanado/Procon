#include<algorithm>
#include<functional>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<climits>

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define FOR(itr,data) for(__typeof((data).begin()) itr=(data).begin();itr!=(data).end();++itr)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

typedef unsigned long long UInt64;
typedef long long Int64;

const int INF=100000000;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

using namespace std;

typedef pair<int ,int > P;

int n;
int ary[100007];
int dp[100007];


int main() {
    dp[1]=dp[2]=1;
    for(int i=3;i<100007;i++) {
        dp[i]=dp[i-2]+1;
    }
    int ans = 0;
    cin>>n;
    rep(i,n) cin>>ary[i];

    int prev=ary[0];
    int cnt=1;
    for(int i=1;i<n+n;i++) {
        int j=i%n;
        if(prev==ary[j]) {
            cnt++;
        }
        else {
            ans=max(ans,dp[cnt]);
            cnt=1;
            prev=ary[j];
        }

    }

    ans = ans==0?-1:ans;
    cout<<ans<<endl;


    return 0;
}



