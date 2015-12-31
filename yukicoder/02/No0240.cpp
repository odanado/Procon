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
// (x-2,y-1),(x-2,y+1),(x-1,y-2),(x-1,y+2),(x+1,y-2),(x+1,y+2),(x+2,y-1),(x+2,y+1)
int dx[]={-2,-2,-1,-1,1,1,2,2};
int dy[]={-1,1,-2,2,-2,2,-1,1};
using namespace std;
typedef pair<int ,int > P;
typedef long long ll;

const int offset = 100;
bool ok[202][202];
void dfs(int x,int y,int n) {

    ok[x+offset][y+offset]=true;
    if(n==0) return;
    rep(k,8) {
        int ny=y+dy[k];
        int xn=x+dx[k];
        dfs(xn,ny,n-1);
    }
}
int main() {
    dfs(0,0,3);
    int x,y;
    cin>>x>>y;
    if(!((-100<=x&&x<=100)&&(-100<=y&&y<=100))) {
        cout<<"NO"<<endl;
        return 0;
    }
    if(ok[x+offset][y+offset]) {
        cout<<"YES"<<endl;
    }
    else {
        cout<<"NO"<<endl;
    }

    return 0;
}

