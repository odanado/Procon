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

int n,q;

void solve(){
    int ary[110];
    memset(ary,0,sizeof(ary));

    rep(i,n) {
        int a,m;
        cin>>m;
        rep(j,m){
            cin>>a;
            ary[a]++;
        }
    }
    int ans=0;
    int max=0;

    rep(i,110) {
        if(ary[i] >= q&&max<ary[i]) {
            ans=i;
            max=ary[i];
        }
    }
    cout<<ans<<endl;
}

int main() {

    while(cin>>n>>q) {
        if(!(n+q)) return 0;

        solve();
    }

    return 0;
}



