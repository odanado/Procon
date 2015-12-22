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

int r,n;
void solve() {
    map<int,int> h;
    double ans=INF;
    rep(i,n) {
        int x1,x2,t;
        cin>>x1>>x2>>t;
        for(int x=x1;x<x2;x++) h[x]=max(h[x],t);
    }
    for(int x=-r;x<r;x++) {
        int x1=x;
        double y=sqrt(r*r-x1*x1);
        //printf("%d : %d %.10f\n",x,h[x],r-y);
        ans=min(ans,h[x]+r-y);
        x1++;
        if(h.count(x1)) {
            double y=sqrt(r*r-x1*x1);
            //printf("%d : %d %.10f\n",x,h[x],r-y);
            ans=min(ans,h[x]+r-y);
        }
    }

    printf("%.10f\n",ans);
}
int main() {
    while(cin>>r>>n) {
        if(!r) break;
        solve();
    }
    return 0;
}

