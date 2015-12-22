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
int m;
vector<P> origin;
void rotation(vector<P>& vec) {
    rep(i,vec.size()) {
        P p = vec[i];
        vec[i]=P(-p.sc,p.fr);
    }
}
bool ok2(vector<P>& vec) {
    if(vec.size()!=origin.size()) return false;
    bool ret = true;
    int diff1 = origin[0].fr-vec[0].fr;
    int diff2 = origin[0].sc-vec[0].sc;

    rep(i,vec.size()) {
       bool t = diff1 == origin[i].fr - vec[i].fr; 
       t &= diff2 == origin[i].sc - vec[i].sc; 
       ret &= t;
    }
    return ret;
}
bool ok(vector<P>& vec) {
    bool ret = false;
    rep(i,5) {
        ret |= ok2(vec);
        rotation(vec);
        reverse(all(vec));
        ret |= ok2(vec);
        reverse(all(vec));
    }
    return ret;
}
void solve() {
    vector<vector<P> > data;
    cin>>m;
    origin.resize(m);
    
    rep(i,m) {
        int x,y;
        cin>>x>>y;
        origin[i] = P(x,y);
    }
    rep(i,n) {
        cin>>m;
        vector<P> t(m);
        rep(j,m) {
            int x,y;
            cin>>x>>y;
            t[j]=P(x,y);
        }
        data.pb(t);
    }

    rep(i,data.size()) {
        if(ok(data[i])) {
            cout<<i+1<<endl;
        }
    }

    origin.clear();
}
int main() {
    while(cin>>n) {
        if(n==0) return 0;
        solve();
        cout<<"+++++"<<endl;
    }
    return 0;
}

