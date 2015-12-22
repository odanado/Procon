#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
#include <cstdint>
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
void solve() {
    int n;
    cin>>n;
    int ans1=0,ans2=0;
    int prev;
    cin>>prev;
    rep(i,n-1) {
        int a;
        cin>>a;
        if(a<prev) ans1=max(ans1,prev-a);
        else ans2=max(ans2,a-prev);
        prev = a;
    }
    swap(ans1,ans2);
    cout<<ans1<<" "<<ans2<<endl;


}

int main() {
    
    int t;
    cin>>t;
    rep(i,t) solve();
    return 0;
}

