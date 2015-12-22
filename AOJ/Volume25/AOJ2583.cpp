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
vector<string> vec;

void solve() {
    vec.clear();
    vec.reserve(n);
    rep(i,n) {
        string s;
        cin>>s;
        vec.pb(s);
    }
    rep(i,n) {
        rep(j,vec[i].size()) {
            if(vec[i][j]!='.') continue;
            if(vec[i][j+1]!='.') vec[i][j]='+';
        }
    }
    rep(i,n) {
        rep(j,vec[i].size()) {
            if(vec[i][j]!='+') continue;
            int idx=-1;
            for(int k=i+1;k<n;k++) {
                if(vec[k].size() <= j) break;
                if(vec[k][j]=='+') {
                    idx=k;
                    break;
                }
                if(vec[k][j]!='.') break;
            }
            if(idx!=-1) {
                for(int k=i+1;k<idx;k++) vec[k][j]='|';
            }
        }
    }
    rep(i,n) rep(j,vec[i].size()) if(vec[i][j]=='.') vec[i][j]=' ';
    rep(i,n) cout<<vec[i]<<endl;

}

int main() {
    while(cin>>n) {
        if(n==0) break;
        solve();
    }
    return 0;
}

