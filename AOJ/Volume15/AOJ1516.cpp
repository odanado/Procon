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

string btn[3]={"ABC","DEF","GHI"};

bool dfs(string &str,int pos,P p) {
    if(str.size()==pos) return true;
    bool ret=false;
    rep(k,4) {
        int ny=p.fr+dy[k];
        int nx=p.sc+dx[k];
        if(ny<0||nx<0) continue;
        if(ny>=3||nx>=3) continue;
        if(str[pos]!=btn[ny][nx]) continue;
        ret |= dfs(str,pos+1,P(ny,nx));
    }

    return ret;
}

bool ok(string str) {
    P s;
    rep(y,3) rep(x,3) if(btn[y][x]==str[0]) s=P(y,x);

    return dfs(str,1,s);
}

int main() {
    int q=1000;
    while(q-->0) {
        string s;
        cin>>s;
        if(ok(s)) cout<<s<<endl;
    }
    return 0;
}

