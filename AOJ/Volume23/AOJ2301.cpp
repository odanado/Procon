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

int K,R,L;
double P,E,T;

inline double dfs(int depth,double r,double l) {
    //cout<<string(depth,'\t');printf("%.8f %.8f\n",l,r);
    if(depth==K) {
        //string(depth,'\t');printf("%.8f %d\n",(l+r)/2,abs(T-(l+r)/2)<=E);
        return 1.0*(abs(T-(l+r)/2)<=E);
    }
    double h=(l+r)/2;

    if(l<T-E) return 0;
    if(r>T+E) return 0;
    if(T-E<=r&&l<=T+E) return 1;

    double ret=0.0;
    if(h>=T) {
        ret+=dfs(depth+1,r,h)*(1-P);
        ret+=dfs(depth+1,h,l)*(P);
    }
    else {
        ret+=dfs(depth+1,r,h)*(P);
        ret+=dfs(depth+1,h,l)*(1-P);
    }

    return ret;
}


int main() {
    cin>>K>>R>>L;
    cin>>P>>E>>T;

    printf("%.20f\n",dfs(0,R,L));
    return 0;
}

