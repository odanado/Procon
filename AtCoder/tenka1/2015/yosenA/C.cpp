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
int M,N;
int A[100][100],B[100][100];

int dfs(int y,int x) {
    //cout<<y<<", "<<x<<endl;
    int ret=INF;
    if(y==M) return 0;
    if(x==N) return dfs(y+1,0);
    if(A[y][x]!=B[y][x]) {
        int t=A[y][x];
        A[y][x]=B[y][x];
        ret=min(ret,dfs(y,x+1)+1);
        A[y][x]=t;
        rep(i,4) {
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(ny<0||nx<0) continue;
            if(ny>=M||nx>=N) continue;
            if(A[ny][nx]==B[y][x]) {
                swap(A[y][x],A[ny][nx]);
                ret=min(ret,dfs(y,x+1)+1);
                swap(A[y][x],A[ny][nx]);
            }
        }
    }
    else ret=min(ret,dfs(y,x+1));

    return ret;
}

int main() {
    cin>>M>>N;
    rep(i,M) rep(j,N) cin>>A[i][j];
    rep(i,M) rep(j,N) cin>>B[i][j];
    if(N<=10&&M<=10) cout<<dfs(0,0)<<endl;
    return 0;
}

