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

int X,Y,W,H;
int N;

void solve() {
    cin>>X>>Y>>W>>H;
    cin>>N;
    int ans=0;
    rep(i,N) {
        int x,y;
        cin>>x>>y;
        if(X<=x&&x<=X+W && Y<=y&&y<=Y+H) ans++;
    }
    cout<<ans<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t-->0) solve();
    return 0;
}

