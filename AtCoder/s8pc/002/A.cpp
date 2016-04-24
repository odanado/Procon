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
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

const ll INF = 1e9;
const ll MOD = 1e9 + 7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    string s, t;
    cin >> s;
    char pre = s.front();
    t+=pre;
    rep(i,s.size()) if(i) {
        while(i<s.size()&&pre==s[i]) i++;
        if(i==s.size()) break;
        pre=s[i];
        t+=s[i];
    }
    int a=0,b=0;
    rep(i,t.size()) {
        if(t[i]=='I') {
            a=i;
            break;
        }
    }
    rep(i,t.size()) {
        int j=t.size()-i-1;
        if(t[j]=='I') {
            b=j;
            break;
        }
    }
    if(t.find('I')==string::npos) cout<<"0"<<endl;
    else cout<<b-a+1<<endl;
    return 0;
}
