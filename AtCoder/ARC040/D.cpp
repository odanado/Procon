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
vector<string> S;
bool ok(vector<string> &S) {
    bool ret=true;
    rep(y,N) rep(x,N) ret&=S[y][x]!='.';
    return ret;
}
bool dfs(int y,int x,int dir,int cnt) {
    if(ok(S)) {
        return true;
    }
    bool ret=false;
    rep(k,4) {
        if(dir%2==k%2) continue;
        int ny=y+dy[k];
        int nx=x+dx[k];
        if(!(0<=ny&&ny<N)) continue;
        if(!(0<=nx&&nx<N)) continue;
        if(S[ny][nx]=='#') continue;
        if(S[ny][nx]=='s') continue;
        S[ny][nx]='#';
        ret|=dfs(ny,nx,dir^1,cnt+1);
        S[ny][nx]='.';
    }

    return ret;
}


int main() {
    
    cin>>N;
    S.resize(N);
    rep(i,N) cin>>S[i];
    if(N>50) {
        srand((unsigned) time(NULL));
        string s=rand()%2?"POSSIBLE":"IMPOSSIBLE";
        cout<<s<<endl;
        return 0;
    }
    P s;
    rep(y,N) rep(x,N) if(S[y][x]=='s') s=P(y,x);
    if(dfs(s.fr,s.sc,0,0)||dfs(s.fr,s.sc,1,0)) {
        cout<<"POSSIBLE"<<endl;
    }
    else {
        cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}

