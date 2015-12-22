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

int f(int y,int m,int d) {
    if(m<=2) y--,m+=12;
    int res = 365*y;
    res+=((int)y/4 - (int)y/100 + (int)y/400);
    res += ((int)(306*(m+1)/10));
    res += d;
    res -=429;
    return res;
}

int main() {
    int y,m,d;
    cin>>y>>m>>d;
    cout<<(f(2014,5,17)-f(y,m,d))<<endl;
    return 0;
}

/* 2014/05/17 AC */

