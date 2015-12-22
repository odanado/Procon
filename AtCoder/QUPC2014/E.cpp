#include<algorithm>
#include<functional>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<climits>

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define FOR(itr,data) for(__typeof((data).begin()) itr=(data).begin();itr!=(data).end();++itr)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

typedef unsigned long long UInt64;
typedef long long Int64;

const int INF=100000000;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

using namespace std;

typedef pair<int ,int > P;

double x,y,vx,vy,vh;

int main() {
    cin>>x>>y>>vx>>vy>>vh;
    double t1=0.0,t2=10000000000.0,mid;
    rep(i,10000000) {
        mid = (t1+t2)/2.0;
        if((x+vx*mid)*(x+vx*mid)+(y+vy*mid)*(y+vy*mid) < (mid*vh)*(mid*vh)) t2=mid;
        else t1=mid;
    }
    if((x+vx*mid)*(x+vx*mid)+(y+vy*mid)*(y+vy*mid) - (mid*vh)*(mid*vh)>1e-8) 
        puts("IMPOSSIBLE");
    else
        cout<<mid<<endl;
    return 0;
}



