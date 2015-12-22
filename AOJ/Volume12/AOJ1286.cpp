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

const int MAX_SIZE=100005;
int n,m,k;
double p[2][MAX_SIZE];
void solve() {
    rep(i,MAX_SIZE) p[0][i]=p[1][i]=0.0;

    rep(i,m) p[0][i+1]=1.0/m;
    rep(i,n-1) {
        rep(j,MAX_SIZE) {
            rep(k,m) {
                if(k+j+1>=MAX_SIZE) continue;
                p[1][k+j+1]+=p[0][j]/m;
            }
        }
        rep(j,MAX_SIZE) {
            p[0][j]=p[1][j];
            p[1][j]=0.0;
        }
    }
    double ans = 0.0;

    rep(i,m*n) {
        int b = max(1,i-k+1);
        //cout<<i+1<<" : "<<p[0][i+1]<<","<<b<<endl;
        ans += p[0][i+1]*b;
    }

    printf("%.8f\n",ans);
}

int main() {
    while(cin>>n>>m>>k) {
        if(n+m+k==0) break;
        solve();
    }
    return 0;
}

