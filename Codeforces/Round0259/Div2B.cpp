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
int a[100005];
bool ok(vector<int> const& vec) {
    rep(i,vec.size()) {
        if(i==0) continue;
        if(vec[i-1]>vec[i]) return false;
    }
    return true;
}
int main() {
    vector<int> vec;
    vector<vector<int> > S;
    cin>>n;
    rep(i,n) cin>>a[i];
    vec.pb(a[0]);
    rep(i,n) {
        if(a[i]<=a[i+1]) {
            vec.pb(a[i+1]);
        }
        else {
            S.pb(vec);
            vec.clear();
            vec.pb(a[i+1]);
        }
    }
    /*
    rep(i,S.size()) {
        rep(j,S[i].size()) {
            cout<<S[i][j]<<" ";
        }
        cout<<endl;
    }
    // */
    if(S.size()==1) {
        if(ok(S[0])) 
            cout<<"0"<<endl;
        else
            cout<<"-1"<<endl;
        return 0;
    }
    if(S.size()>2) {
        cout<<"-1"<<endl;
        return 0;
    }
    vector<int> t(S[0].size()+S[1].size());
    rep(i,S[1].size()) t[i]=S[1][i];
    rep(i,S[0].size()) t[i+S[1].size()]=S[0][i];

    /*
    rep(i,t.size()) cout<<t[i]<<" ";
    cout<<endl;
    // */
    if(ok(t)) {
        cout<<S[1].size()<<endl;
    }
    else {
        cout<<"-1"<<endl;
    }
    return 0;
}

