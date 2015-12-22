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
 
string s;
vector<string> vec;
 
void func(int idx,int S) {
    if(s.size()==idx) {
        vec.pb(s);
        return;
    }
 
    int p=s[idx]-'a';
    if(s[idx]!='z' && !((S>>(p+1))&1)) {
        s[idx]++;
        func(idx+1,S|(1<<p));
        s[idx]--;
    }
    if((S>>p)&1) func(idx+1,S);
 
}
 
void solve() {
    string t(s);
    vec.clear();
    func(0,0);

    sort(all(vec));

    cout<<vec.size()<<endl;
    if(vec.size()<=10) {
        for(auto &e : vec) {
            cout<<e<<endl;
        }
    }
    else {
        auto it = vec.begin();
        rep(i,5) {
            cout<<*it<<endl;
            ++it;
        }
        it = vec.end();
        rep(i,5) {
            --it;
            cout<<*it<<endl;
        }
    }
 
}
 
int main() {
    while(cin>>s) {
        if(s=="#") break;
        solve();
 
    }
    return 0;
}
