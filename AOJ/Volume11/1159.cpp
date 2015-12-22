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

int n,p;

bool check(int *a) {
    int cnt=0;
    rep(i,n) if(a[i]!=0) cnt++;
    return cnt==1;
}

void solve() {
    int ary[100]={};
    int wan=p;

    int index = 0;
    while(true) {
        if(wan==0) {
            if(p==ary[index]) break;
            wan = ary[index];
            ary[index] = 0;
        }
        else {
            wan--;
            ary[index]++;
        }
        index++;
        index%=n;
    }
    //index=index+n-1;
    //index%=n;
    cout<<index<<endl;


}

int main() {
    while(cin>>n>>p){
        if(!(n+p)) return 0;
        solve();
    }
    return 0;
}



