#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
using ll = long long;

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

const ll INF=1e9;
const ll MOD=1e9+7;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int n;
int d[1003];
set<int> st;
int to_i(string s) {
    int n;
    stringstream ss;
    ss<<s;
    ss>>n;
    return n;
}
int main() {
    cin>>n;
    rep(i,n) cin>>d[i];
    rep(i,n) {
        string s;
        s=string(1, d[i]+'0');
        st.insert(to_i(s));
        rep(j,n) if(i<j) {
            s+=string(1, d[j]+'0');
            st.insert(to_i(s));
            if(s.size()==6) break;
        }
    }
    rep(i,1000000) {
        if(!st.count(i)) {
            cout<<i<<endl;
            break;
        }
    }

    return 0;
}

