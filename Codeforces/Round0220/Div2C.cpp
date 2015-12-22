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

    int ans = 0;
int n,m;
string maze[101];
char f(char ss) {
    if(ss=='D') return 'I';
    if(ss=='I') return 'M';
    if(ss=='M') return 'A';
    if(ss=='A') return 'D';
}

void dfs(int x,int y,int s) {

    if(s == 10000) {
        return;
    }
    rep(i,4) {
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(0<=nx&&nx<n && 0<=ny&&ny<m && f(maze[x][y]) == maze[nx][ny])
            dfs(nx,ny,s+1);
    }
    s++;
    ans=max(ans,s/4);
    return;
}

int main()
{
    cin>>n>>m;
    rep(i,n) cin>>maze[i];

    rep(i,n) rep(j,m) if(maze[i][j]=='D') dfs(i,j,0);
    cout<<ans<<endl;
    
    return 0;
}



