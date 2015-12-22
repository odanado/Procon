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

int64_t f() {
    int64_t a = k;
    int64_t t = min(a,n-1);
    int64_t ans = (1.0*n/(t+1));
    a-=t;
    if(a<=0) {
        return ans*m;
    }

    t = min(a,m-1);
    int64_t tmp = (m/(t+1));

    a-=t;
    if(a<=0) {
        return ans*tmp;
    }
    else {
        return -1;
    }
}

int main() {
    cin>>n>>m>>k;
    int64_t ans = f();
    swap(n,m);
    ans = max(f(),ans);

    cout<<ans<<endl;
    return 0;
}

