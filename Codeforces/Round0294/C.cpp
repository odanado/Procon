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
int n,m;

int func(int i) {
    int a=n-i;
    int b=m-2*i;
    if(a<0 || b<0) return -INF;
    return min(a/2,b);
}
int main() {
    cin>>n>>m;
    int ans=0;
    int a=min(n,m/2)*3;
    rep(i,a) ans=max(ans,func(i)+i);
    cout<<ans<<endl;
    return 0;
}

