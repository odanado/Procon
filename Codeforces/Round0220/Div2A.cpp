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

int n,m,i,j,a,b;

int check(int x,int y) {
    x = abs(x-i);
    y = abs(y-j);

    if(x%a==0 && y%b==0 && (((x/a)&1) == ((y/b)&1))) {
        return max(x/a,y/b);
    }
    return INF;
}

int main()
{
    cin>>n>>m>>i>>j>>a>>b;

    int ans=INF;
    ans = min(ans,check(1,m));
    ans = min(ans,check(n,1));
    ans = min(ans,check(n,m));
    ans = min(ans,check(1,1));
    if(ans==INF) {
        puts("Poor Inna and pony!");
    }
    else {
        printf("%d\n",ans);
    }


  return 0;
  }


