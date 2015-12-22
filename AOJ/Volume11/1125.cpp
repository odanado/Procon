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

int n;
int map[110][110];

int cnt(int x0,int y0,int x1,int y1) {
    int res=0;
    for(int i=x0;i<x1;i++) {
        for(int j=y0;j<y1;j++) {
            if(map[i][j]=='*') res++;
        }
    }

    return res;

}

void solve() {

    rep(i,110) rep(j,110) map[i][j]=0;
    int h,w,s,t;
    int x[510]={},y[510]={};
    cin>>w>>h;
    rep(i,n) {
        cin>>x[i]>>y[i];
        map[x[i]][y[i]]='*';
    }
    cin>>s>>t;

    int ans = 0;

    for(int i=1;i<=1+w-s;i++) {
        for(int j=1;j<=1+h-t;j++) {
            ans=max(ans,cnt(i,j,i+s,j+t));
        }
    }
    cout<<ans<<endl;

}

int main() {
    while(cin>>n) {
        if(!n) return 0;
        solve();

    }
    return 0;
}



