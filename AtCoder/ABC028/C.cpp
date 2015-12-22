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

int main() {
    int A[5];
    vector<int> ans;
    rep(i,5) cin>>A[i];
    rep(S,1<<5) {
        if(__builtin_popcount(S)==3) {
            int t=0;
            rep(i,5) if(S>>i&1) t+=A[i];
            ans.pb(t);
        }
    }
    sort(all(ans));
    ans.erase(unique(all(ans)),ans.end());
    reverse(all(ans));
    cout<<ans[2]<<endl;
    return 0;
}

