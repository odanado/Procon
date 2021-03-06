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

bool ok[101];
int n,m;
int main() {
    cin>>n>>m;
    rep(i,n) {
        int x,y;
        cin>>x;
        rep(j,x) {
            cin>>y;
            ok[y-1]=true;
        }
    }
    bool ans=true;
    rep(i,m) ans&=ok[i];
    if(ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}

