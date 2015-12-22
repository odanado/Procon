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

string str;
int n,e,i,t;

int main() {
    cin>>str;
    bool f = true;

    rep(j,str.size()) {
        if(str[j]=='n') n++;
        if(str[j]=='e') e++;
        if(str[j]=='i') i++;
        if(str[j]=='t') t++;
    }
    int ans = 0;
    int a = 3;

    while(n >=a && e >=3 && i>=1 && t>=1) {
        ans++;
        n-=a;
        e-=3;
        i--;
        t--;
        if(f) {
            a = 2;
            f=false;
        }
    }
    cout<<ans<<endl;

    return 0;
}


