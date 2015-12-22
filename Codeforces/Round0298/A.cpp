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
    int n;
    cin>>n;
    vector<int> ans;
    rep(i,n+1) {
        if(!i) continue;
        if(i%2==1) ans.pb(i);
    }
    reverse(all(ans));
    for(int i=n;i>1;i--) {
        if(i%2==0&&abs(ans[ans.size()-1]-i)!=1) ans.pb(i);
    }
    cout<<ans.size()<<endl;
    rep(i,ans.size()) {
        printf("%d%c",ans[i],i+1==n?'\n':' ');
    }

    return 0;
}

