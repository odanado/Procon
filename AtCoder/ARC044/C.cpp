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

struct Beam {
    int t,d,a;
    Beam(int t=0,int d=0,int a=0) : 
        t(t),d(d),a(a){}
    bool operator<(const Beam &rhs) const {
        return t<rhs.t;
    }
};

int W,H,Q;
vector<Beam> vec;
int grid[102][102];
int main() {
    cin>>W>>H>>Q;
    rep(i,Q) {
        int t,d,a;
        cin>>t>>d>>a;
        vec.pb(Beam(t,d,a));
    }
    sort(all(vec));
    rep(i,vec.size()) {
        if(vec[i].d==0) {
            rep(y,H) grid[y][vec[i].a]=1;
        }
        else rep(x,W) grid[vec[i].a][x]=1;
    }
    cout<<endl;
    rep(y,H) {
        rep(x,W) cout<<grid[y][x]<<" ";
        cout<<endl;
    }
    return 0;
}

