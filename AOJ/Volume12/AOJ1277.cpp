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

int N,T,L,B;
bool Lose[102];
bool Back[102];

int next_pos(int pos,int n) {
    int cnt=0;
    int a=1;
    while(cnt < n) {
        if(pos == N) a=-1;
        if(pos == 0) a=1;
        pos+=a;
        cnt++;
    }

    return pos;
}
double dp[102][102];

// ターン数,場所
double dfs(int a,int b) {
    if(b == N) return 1;
    if(a >= T) return 0;
    if(dp[a][b]!=-1) return dp[a][b];

    double res=0.0;
    rep(i,6) {
        int next = next_pos(b,i+1);
        if(Lose[next]) res += dfs(a+2,next) / 6.0;
        else if(Back[next]) res += dfs(a+1,0)/6.0;
        else res += dfs(a+1,next)/6.0;
    }

    return dp[a][b] = res;
}

void solve() {
    rep(i,102) Lose[i]=Back[i]=false;
    rep(i,102) rep(j,102) dp[i][j]=-1;
    rep(i,L) {
        int a;
        cin>>a;
        Lose[a]=true;
    }
    rep(i,B) {
        int a;
        cin>>a;
        Back[a]=true;
    }

    printf("%.6f\n", dfs(0,0));
}

int main() {
    while(cin>>N>>T>>L>>B) {
        if(N+T+L+B==0) break;
        solve();
    }
    return 0;
}

