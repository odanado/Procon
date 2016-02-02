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

int n;
ll a[100005];
ll ans,sum;
int main() {
    cin>>n;
    rep(i,n) cin>>a[i];
    rep(i,n) sum+=a[i];
    if(sum%2==0) ans=sum;
    rep(i,n) {
        if(sum%2==1&&a[i]%2==1) {
            ans=max(ans,sum-a[i]);
        }
    }
    cout<<ans<<endl;
    return 0;
}

