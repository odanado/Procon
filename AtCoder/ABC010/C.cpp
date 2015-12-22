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

int x10,y10;
int x20,y20;
int T,V;
int n;
int x[1003],y[1003];

bool check(int x_, int y_) {
   double t = sqrt((x_-x10)*(x_-x10)+(y_-y10)*(y_-y10)); 
   t +=  sqrt((x_-x20)*(x_-x20)+(y_-y20)*(y_-y20));

   double tt = 1.0*T*V;

   return t <= tt;


}

int main() {
    cin>>x10>>y10>>x20>>y20;
    cin>>T>>V;
    cin>>n;
    rep(i,n) cin>>x[i]>>y[i];

    bool flag=false;
    rep(i,n) flag|=check(x[i],y[i]);
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;



    return 0;
}



