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
bool ok(int *a,int *b) {
    rep(i,26) if(b[i]&&a[i]<b[i]) return false;

    return true;
}

void solve(string &a,const string &b,int *a_cnt,int *b_cnt) {
    rep(i,b.size()) {
        auto it=lower_bound(all(a),b[i]);
        a_cnt[b[i]-'a']--;

        a.erase(it);
    }
}

string a,b,c;
int main() {
    int a_cnt[26]={};
    int b_cnt[26]={};
    int c_cnt[26]={};
    cin>>a>>b>>c;
    sort(all(a));
    rep(i,a.size()) a_cnt[a[i]-'a']++;
    rep(i,b.size()) b_cnt[b[i]-'a']++;
    rep(i,c.size()) c_cnt[c[i]-'a']++;
    string ans="";
    while(ok(a_cnt,b_cnt) || ok(a_cnt,c_cnt)) {
        if(ok(a_cnt,b_cnt)) {
            ans+=b;
            solve(a,b,a_cnt,b_cnt);
        }
        if(ok(a_cnt,c_cnt)) {
            ans+=c;
            solve(a,c,a_cnt,c_cnt);
        }
    }
    cout<<ans<<a<<endl;
    return 0;
}

