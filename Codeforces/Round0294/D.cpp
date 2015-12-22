#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <climits>

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

const int INF=100000000;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
using namespace std;
typedef pair<int ,int > P;
typedef long long ll;

int cost[26];
ll sum[100005];
string s;

int main() {
    rep(i,26) {
        int x;
        cin>>x;
        cost[i]=x;
    }
    cin>>s;
    rep(i,s.size()) {
        sum[i+1]+=sum[i]+cost[s[i]-'a'];
    }
    rep(i,s.size()) {
        printf("%c %d\n",s[i],sum[i]);
    }
    ll ans=0;
    rep(i,26) {
        map<ll,int> m;
        rep(j,s.size()) if(s[j]==i+'a') {
            ans+=m[sum[j]];
            m[sum[j+1]]++;
        }
    }
    cout<<ans<<endl;




    return 0;
}

