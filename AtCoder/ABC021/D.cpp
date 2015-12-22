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

const int MOD=1000000007;
int n,k;

// [a,n] でidx
int dfs(int a,int b) {
    if(n-a<b) return 0;
    printf("[debug] %d %d\n",a,b);
    if(b==1) return n-a;

    int res=0;
    for(int i=a;i<=n;i++) {
        res+=dfs(i+1,b-1);
        res%=MOD;
    }
    return res;
}

int main() {
    cin>>n>>k;
    cout<<dfs(1,k)<<endl;
    return 0;
}

