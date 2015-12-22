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

int L,R;
vector<int> vec;

int main() {
    int ans=0;
    cin>>L>>R;
    rep(i,L) {
        int a;cin>>a;
        vec.pb(a);
    }
    rep(i,R) {
        int a;cin>>a;
        rep(j,vec.size()) {
            if(a==vec[j]) {
                vec[j]=-1;
                ans++;
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}



