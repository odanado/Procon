#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
#include <cstdint>
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

int64_t n,m,k;
int64_t c(int64_t x) {
    int64_t ret = 0;
    x--;
    rep(i,n+1) if(i) ret+=min(m,x/i);
    //cout<<x+1<<","<<ret<<endl;
    return ret;
}

int main() {
    cin>>n>>m>>k;

    int64_t l=1,r=m*n+1;
    while(l<r) {
        int64_t x = (l+r)>>1;
        if(c(x)<k) l = x+1;
        else r = x;
    }
    cout<<r-1<<endl;
    return 0;
}

