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
int H[3003];
int M[3003];
int S[3003];
int E[3003];

bool ok[3003][3003];
// 何番目以降,前回見た映画,何連続
int dfs(int a,int b,int c) {
    if(a == N) return 0;
    cout<<a<<","<<b<<","<<c<<endl;
    int ret = 0;

    int nx = a + 1;

    if(b == -1 || ok[nx][b]) {
        if(b==-1) {
            ret = max(ret,dfs(nx,M[nx],0)+H[0]);
        }
        else if(M[b] == M[nx]) {
            ret = max(ret,dfs(nx,M[nx],c+1)+H[c+1]);
        }
        else {
            ret = max(ret,dfs(nx,M[nx],0)+H[0]);
        }
    }
    else {

    }
    ret = max(ret,dfs(nx,b,c));

    return ret;

}
int main() {
    cin>>N;
    rep(i,N) cin>>H[i];
    rep(i,N) cin>>M[i]>>S[i]>>E[i];
    rep(i,N) {
        rep(j,N) {
            ok[i][j] = (E[i] <= S[j] || E[j] <= S[i]);
        }
    }

    cout<<dfs(0,-1,0)<<endl;
    return 0;
}

