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
typedef long long ll;

int N,P;
// どっちのターン,残っている石,最大何個取れるか
bool dfs(int a,int b,int c) {
    printf("[debug] %d,%d,%d\n", a,b,c);
    if(b==0) return a^1;
    rep(i,c+1) {
        if(!i) continue;
        if(b-i<0) break;
        if(dfs(a^1,b-i,c+1)) return 1;

    }
    return 0;

}
int main() {
    cin>>N>>P;
    cout<<dfs(0,N,P)<<endl;
    return 0;
}

