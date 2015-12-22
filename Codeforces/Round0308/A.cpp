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

ll a[200][200];
int main() {
    int n;
    cin>>n;
    rep(i,n) {
        int x1,y1;
        int x2,y2;
        cin>>x1>>y1>>x2>>y2;
        for(int x=x1;x<=x2;x++) for(int y=y1;y<=y2;y++) a[x][y]++;
    }
    ll ans=0;
    rep(i,200) rep(j,200) ans+=a[i][j];
    cout<<ans<<endl;
    return 0;
}

