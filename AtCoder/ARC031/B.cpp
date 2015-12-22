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

string A[10];
int cnt;
int cnt2;

int dfs(int x,int y) {
    rep(i,4) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(!(0<=nx&&nx<=9)) continue;
        if(!(0<=ny&&ny<=9)) continue;
        if(A[nx][ny] == 'x') continue;
        A[nx][ny]='x';
        cnt2++;
        dfs(nx,ny);
    }
}
int func(int a,int b) {
    string B[10];

    cnt2 = 0;
    rep(i,10) B[i]=A[i];
    A[a][b] = 'o';
    dfs(a,b);
    rep(i,10) A[i]=B[i];

    return cnt2;
}

int main() {
    rep(i,10) cin>>A[i];
    rep(i,10) rep(j,10) if(A[i][j]=='o') cnt++;
    rep(i,10) rep(j,10) {
        func(i,j);
        // cout<<cnt2<<","<<cnt<<endl;
        if(cnt2 == cnt+1) {
            cout<<"YES"<<endl;
            return 0;
        }
    }

    cout<<"NO"<<endl;
    return 0;
}

