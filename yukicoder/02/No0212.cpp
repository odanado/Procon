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

int dice1[] = {2,3,5,7,11,13};
int dice2[] = {4,6,8,9,10,12};
int P,Q;
double dfs(int cnt,int dice[],int n) {
    if(cnt==n) return 1;
    double ret = 0;
    rep(i,6) ret += dfs(cnt+1, dice, n)*dice[i]/6.0;

    return ret;
}
int main() {
    cin>>P>>Q;
    double ans = dfs(0,dice1,P);
    ans*=dfs(0,dice2,Q);
    printf("%.12f\n",ans);
    return 0;
}

