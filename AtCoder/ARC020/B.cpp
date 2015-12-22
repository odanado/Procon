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

int n,c;
int a[100];

int f(int a1,int a2) {
    int ary[2]={a1,a2};
    int res=0;
    rep(i,n) {
        if(a[i]!=ary[i&1]) res++;
    }
    return res;
}

int main() {
    cin>>n>>c;
    rep(i,n) cin>>a[i];
    int ans=INF;
    rep(i,10) rep(j,10) {
        if(i==j) continue;
        ans=min(ans,f(i+1,j+1));
        ans=min(ans,f(j+1,i+1));
    }
    cout<<ans*c<<endl;



    return 0;
}



