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

string A,B,C,D;

int ary[4];

bool f(int k) {
    int a=1,b=1;
    rep(i,4) {
        if(i==k) continue;
        if(!(ary[k]*2 <= ary[i])) {
            a=0;
        }
        if(!(ary[k]>=ary[i]*2)) {
            b=0;
        }
    }
    return a|b;
}

string ans="ABCD";

int main() {
    cin>>A>>B>>C>>D;
    ary[0] = A.size()-2;
    ary[1] = B.size()-2;
    ary[2] = C.size()-2;
    ary[3] = D.size()-2;
    rep(i,4) {
        if(f(i)) {
            cout<<ans[i]<<endl;
            return 0;
        }
    }
    cout<<"C"<<endl;



    return 0;
}



