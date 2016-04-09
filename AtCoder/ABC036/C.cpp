#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
using ll = long long;

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

const ll INF=1e9;
const ll MOD=1e9+7;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};



vector<int> vec;

int main() {
    int N;
    vector<int> a;
    cin>>N;
    a.resize(N);
    rep(i,N) cin>>a[i];
    set<int> s;
    rep(i,N) s.insert(a[i]);
    for(auto e:s) vec.push_back(e);
    sort(all(vec));
    rep(i,N) {
        auto it=lower_bound(all(vec), a[i]);
        cout<<it-vec.begin()<<endl;
    }
    return 0;
}

