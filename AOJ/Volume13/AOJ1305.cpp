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
string parse(string s,vector<string> &vec) {
    int idx=0;
    string res="";
    string tmp="";
    while(s[idx]!=':') {
        tmp+=s[idx];
        idx++;
    }
    res=tmp;
    tmp="";
    idx++;
    while(idx<s.size()) {
        if(s[idx]==',') {
            vec.pb(tmp);
            tmp="";
            idx++;
        }
        if(s[idx]=='.') break;
        tmp+=s[idx];
        idx++;
    }
    vec.pb(tmp);
    return  res;
}
map<string,int> ids;
int to_id(string &s) {
    if(!ids.count(s)) ids[s]=ids.size();

    return ids[s];
}

vector<int> G[1003];
bool flag[1003];
int dfs(int v,int u) {
    if(flag[v]) return 0;
    flag[v]=true;
    if(G[v].size()==0) {
        return 1;
    }
    int ret=0;

    rep(i,G[v].size()) {
        if(G[v][i]==u) continue;
        ret+=dfs(G[v][i],v);
    }

    return ret;
}

void solve() {
    string first_root="";
    ids.clear();
    rep(i,1003) G[i].clear();
    rep(i,1003) flag[i]=false;
    
    rep(i,n) {
        vector<string> vec;
        string s;
        cin>>s;

        string root=parse(s,vec),t;
        if(first_root=="") first_root=root;

        rep(j,vec.size()) {
            t=vec[j];
            G[to_id(root)].pb(to_id(t));
        }
    }

    cout<<dfs(to_id(first_root),-1)<<endl;

}
int main() {
    while(cin>>n) {
        if(n==0) break;
        solve();
    }
    return 0;
}

