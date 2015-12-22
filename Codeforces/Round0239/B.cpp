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

string n,m;
int a[26],b[26];

int main() {
    cin>>n>>m;
    rep(i,n.size()) {
        a[n[i]-'a']++;
    }
    rep(i,m.size()) {
        b[m[i]-'a']++;
    }
    int ans=0;
    rep(i,26) {
        ans+=min(a[i],b[i]);
        if(a[i]==0&&b[i]!=0) {
            puts("-1");
            return 0;
        }
        

    }
    cout<<ans<<endl;
    return 0;
}



