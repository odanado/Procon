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
int N,M;
int C[5],cost[5];

struct Idol {
    int id,p;
};

vector<Idol> idols[5];
double dp[1<<11];

double dfs(int S) {
    if(dp[S]!=-1) return dp[S];
    
    //printf("%d\n",S);

    double ret=INF;
    if(S+1==(1<<N)) return 0;

    rep(i,M) {
        double q=0.0;
        for(auto &idol : idols[i]) {
            if(((S>>idol.id)&1)) {
                q+=idol.p;
            }
        }
        if(q==100) continue;
        double t=cost[i]*100.0/(100-q);
        for(auto &idol : idols[i]) {
            if(((S>>idol.id)&1)) continue;
            t+=idol.p/(100.0-q)*dfs(S|1<<idol.id);
        }

        ret=min(ret,t);
    }

    return dp[S]=ret;
}

int main() {
    rep(i,1<<11) dp[i]=-1.0;
    cin>>N>>M;
    rep(i,M) {
        cin>>C[i]>>cost[i];
        rep(j,C[i]) {
            int a,b;
            cin>>a>>b;
            a--;
            idols[i].push_back({a,b});
        }
    }
    double ans=dfs(0);

    printf("%.8f\n",ans);
    return 0;
}

