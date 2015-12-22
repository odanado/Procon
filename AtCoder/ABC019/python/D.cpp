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

int main() {
    int N;
    cin>>N;
    ll ans=0;
    ll dist;
    int v=1;
    int u;
    rep(i,N+1) if(i&&i!=v) {
        printf("? %d %d\n", v,i);
        fflush(stdout);
        scanf("%lld", &dist);
        if(ans<dist) {
            u=i;
            ans=dist;
        }
    }

    rep(i,N+1) if(i&&i!=u) {
        printf("? %d %d\n", u,i);
        fflush(stdout);
        scanf("%lld", &dist);
        ans=max(ans,dist);
    }

    printf("! %lld\n",ans);
    fflush(stdout);
    return 0;
}

