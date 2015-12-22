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

int n,r;

void solve() {
    int ary[60]={};
    rep(i,n+1) ary[i]=n-i+1;

    rep(i,r) {
        int p,c;
        cin>>p>>c;
        p--;
        int tmp[60]={};
        for(int j=1;j<=p;j++) tmp[j]=ary[j];
        for(int j=1;j<=c;j++) swap(ary[j],ary[j+p]);
        for(int j=c+1;j<=c+p;j++) ary[j]=tmp[j-c];
    }
    cout<<ary[1]<<endl;
}

int main() {
    while(cin>>n>>r) {
        if(!(n+r)) return 0;
        solve();
    }
    return 0;
}



