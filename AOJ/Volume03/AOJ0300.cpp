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
int p[31];
inline void rote1() {
    swap(p[13],p[18]);
    swap(p[7],p[22]);
    swap(p[8],p[23]);
    swap(p[9],p[24]);
    swap(p[10],p[12]);
}
inline void rote2() {
    swap(p[15],p[16]);
    swap(p[1],p[28]);
    swap(p[2],p[29]);
    swap(p[3],p[30]);
    swap(p[19],p[21]);
}
inline void rote3() {
    swap(p[10],p[21]);
    swap(p[1],p[24]);
    swap(p[4],p[27]);
    swap(p[7],p[30]);
    swap(p[16],p[18]);
}
inline void rote4() {
    swap(p[12],p[19]);
    swap(p[3],p[22]);
    swap(p[6],p[25]);
    swap(p[9],p[28]);
    swap(p[13],p[15]);
}
bool ok(vector<int> vec) {
    int t=p[vec[0]];
    rep(i,vec.size()) if(t!=p[vec[i]]) return false;
    return true;
}
bool ok() {
    bool res=true;
    res&=ok({21,20,19});
    res&=ok({16,17,18});
    res&=ok({10,11,12});
    res&=ok({15,14,13});

    res&=ok({1,2,3,4,5,6,7,8,9});
    res&=ok({22,23,24,25,26,27,28,29,30});
    return res;
}

int dfs(int cnt) {
    if(ok()) return cnt;
    if(cnt>7) return INF;
    int res=INF;

    rote1();
    res=min(res,dfs(cnt+1));
    rote1();

    rote2();
    res=min(res,dfs(cnt+1));
    rote2();

    rote3();
    res=min(res,dfs(cnt+1));
    rote3();

    rote4();
    res=min(res,dfs(cnt+1));
    rote4();
    return res;
}

void solve() {
    rep(i,30) cin>>p[i+1];

    cout<<dfs(0)<<endl;
}

int main() {
    cin>>N;
    while(N-->0) solve();
    return 0;
}

