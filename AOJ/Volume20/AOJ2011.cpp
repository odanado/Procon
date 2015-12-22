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
set<int> S[51];
set<int> map[51];


void insert(int idx,const vector<int> &vec) {
    rep(i,vec.size()) {
        map[idx].insert(vec[i]);
    }
}
void insert(int idx, const set<int> &s) {
    auto it=s.begin();
    while(it!=s.end()) {
        map[idx].insert(*it);
        ++it;
    }
}

void solve() {
    rep(i,51) S[i].clear();
    rep(i,51) map[i].clear();
    rep(i,n) {
        int a,b;
        cin>>a;
        rep(j,a) {
            cin>>b;
            S[i].insert(b);
        }
    }

    for(int d=1;d<31;d++) {
        vector<int> t;
        // 暇な人達
        rep(i,n) if(S[i].count(d)) t.pb(i);
        rep(i,t.size()) insert(t[i],t);
        rep(i,t.size()) rep(j,t.size()) insert(t[i],map[t[j]]);

        bool f=false;
        rep(i,n) f|=map[i].size()==n;
        if(f) {
            cout<<d<<endl;
            return;
        }
        
    }

    cout<<"-1"<<endl;
}

int main() {
    while(cin>>n) {
        if(n==0) break;
        solve();
    }
    return 0;
}

