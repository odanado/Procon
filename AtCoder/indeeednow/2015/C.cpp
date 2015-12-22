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
typedef pair<P,int> Pi;
typedef long long ll;
int n,m;
map<Pi,int> data;

int main() {
    cin>>n>>m;
    rep(i,n) {
        int a,b,c,w;
        cin>>a>>b>>c>>w;
        data[Pi(P(a,b),c)]=w;
    }
    rep(i,m) {
        int x,y,z;
        cin>>x>>y>>z;
        auto it = data.lower_bound(Pi(P(x,y),z));
        cout<<it->sc<<endl;
    }
    return 0;
}

