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

map<int,P> mp;
int ary[1005];

int main()
{
    rep(i,1005) ary[i]=i+1;
    int n,m,a;
    cin>>n>>m>>a;

    rep(i,m) {
        int h,p,q;
        cin>>h>>p>>q;
        mp[h]=P(p,q);

    }
    FOR(it,mp) {
        cout<<it->sc.fr<<","<<it->sc.sc<<endl;
        swap(ary[it->sc.fr],ary[it->sc.sc]);

    }
    cout<<ary[a]<<endl;

  
  return 0;
}


