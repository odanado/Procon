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

ll W,H;
int N;
ll S[101],K[101];
set<ll> s1,s2;
map<ll,ll> mp;
int main() {
    cin>>W>>H;
    cin>>N;
    rep(i,N) {
        cin>>S[i]>>K[i];
        s1.insert(K[i]);
        s2.insert(S[i]);
        mp[K[i]]++;
    }
    ll ans=s2.size()*(H-s1.size());
    for(auto e:mp) {
        ans+=W-e.sc;
    }
    cout<<ans<<endl;
    return 0;
}

