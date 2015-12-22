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

typedef long long ll;
const ll INF=1e18;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
using namespace std;
typedef pair<int ,int > P;

ll x[200005];
int n;
int main() {
    cin>>n;
    rep(i,n) cin>>x[i];
    rep(i,n) {
        ll a,b;
        a=INF,b=0;
        if(i+1!=n) a=min(a,abs(x[i]-x[i+1]));
        if(i) a=min(a,abs(x[i-1]-x[i]));

        b=max(b,abs(x[0]-x[i]));
        b=max(b,abs(x[i]-x[n-1]));

        cout<<a<<" "<<b<<endl;
    }
    return 0;
}

