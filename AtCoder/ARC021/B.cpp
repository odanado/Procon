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

int L;
unsigned int B[100007];

int main() {
    unsigned int t=0;
    cin>>L;
    rep(i,L) {
        cin>>B[i];
        t^=B[i];
    }
    if(t!=0) {
        puts("-1");
        return 0;
    }
    
    cout<<(t)<<endl;
    rep(i,L-1) {
        cout<<(t^B[i])<<endl;
        t^=B[i];
    }

    return 0;
}




/* 2014/05/01 */

