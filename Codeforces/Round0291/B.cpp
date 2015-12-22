#include <algorithm>
#include <functional>
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
int x[10004];
int y[10004];
int x0,y0;


int main() {
    set<P> S;
    cin>>n;
    cin>>x0>>y0;
    rep(i,n) cin>>x[i]>>y[i];
    int ans = 0;
    rep(i,n) {
        int ny=y0-y[i];
        int nx=x0-x[i];
        int g = __gcd(nx,ny);
        ny /= g;
        nx /= g;
        S.insert(P(ny,nx));
    }
    cout<<ans+S.size()<<endl;
    return 0;
}

