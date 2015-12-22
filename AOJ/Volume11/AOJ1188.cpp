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

string str;

int calc(vector<int> vec) {
    // cout<<"size = "<<vec.size()<<endl;
    // rep(i,vec.size()) cout<<vec[i]<<" ";
    // cout<<endl;
    int res=0;
    sort(all(vec));
    rep(i,(vec.size()+1)/2) res+=(vec[i]);
    return res;
}

int pos;
int dfs() {
    // cout<<"pos = "<<pos<<endl;
    pos++;
    vector<int> vec;
    if(str[pos]!='[' && str[pos]!=']') {
        string t;
        while(str[pos]!=']') t+=str[pos++];
        pos++;
        return atoi(t.c_str())/2+1;
    }
    while(str[pos]!=']') vec.pb(dfs());

    pos++;
    return calc(vec);
}

void solve() {
    pos=0;
    cout<<dfs()<<endl;
}

int main() {
    int n;
    cin>>n;
    while(n-->0) {
        cin>>str;
        solve();
    }
    return 0;
}

