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

bool isPrime[10004];
int N;
int dp[10004];
int dfs(int n,int d) {
    if(n==0||n==1) return 1;
    //if(n==2||n==3) return 1;
    if(dp[n]!=100) return dp[n];
    int ret = -INF;
    for(int i=n;i>=2;i--) {
        if(isPrime[i]&&n-i>=0) ret = max(ret,-dfs(n-i,d+1));
    }

    //cout<<string(d,' ')<<n<<": "<<ret<<endl;
    return dp[n]=ret;
}
int main() {
    rep(i,10004) dp[i]=100;
    rep(i,10004) isPrime[i]=true;
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i<10004;i++) {
        if(isPrime[i]) for(int j=2*i;j<10004;j+=i) isPrime[j]=false;
    }
    cin>>N;
    if(dfs(N,0)==1) {
        cout<<"Win"<<endl;
    }
    else {
        cout<<"Lose"<<endl;
    }
    return 0;
}

