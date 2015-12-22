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

int N;
int A[2003];
int MOD=1000000007;
int dp[2003][2003];

int main() {
    cin>>N;
    rep(i,N) cin>>A[i];

    dp[0][A[0]]=1;

    rep(i,N) {
        int s=0;
        rep(j,2003) {
            s += dp[i][j];
            s %= MOD;
            /*
            for(int k=0;k<=j;k++) {
                s+=dp[i][k];
                s%=MOD;
            }
            */
            if(A[i+1]==-1) {
                dp[i+1][j] += s;
            }
            else {
                if(A[i+1]!=j) dp[i+1][j]=0;
                else dp[i+1][j] = s;
            }
            dp[i+1][j] %= MOD;

        }
        //if(A[i]!=-1) rep(j,2003) if(j!=A[i]) dp[i+1][j]=0;
    }

    cout<<dp[N-1][A[N-1]]<<endl;

    return 0;
}

/* 2014/05/17 80 */

