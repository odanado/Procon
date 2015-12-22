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

int N;
int a,b;
int M;
vector<int> G[207];
int bfs() {
    int d[102];
    rep(i,102) d[i]=INF;
    d[a]=0;
    queue<int> que;
    que.push(a);

    while(que.size()) {
        int p=que.front(); que.pop();
        rep(i,G[p].size()) {
            int v=G[p][i];
            if(d[v] > d[p]+1) {
                d[v]=d[p]+1;
                que.push(v);
            }
        }
    }
    return d[b];
}
const int MOD=1000000007;
int main() {
    cin>>N;
    cin>>a>>b;
    cin>>M;
    rep(i,M) {
        int x,y;
        cin>>x>>y;
        G[x].pb(y);
        G[y].pb(x);
    }
    int s=bfs();
    int dp[107][207];
    dp[0][a]=1;
    rep(i,105) rep(j,205) {
        rep(k,G[j].size()) {
            dp[i+1][G[j][k]]+=dp[i][j];
            dp[i+1][G[j][k]]%=MOD;
        }
    }
    cout<<dp[s][b]%MOD<<endl;
    return 0;
}

