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

bool ok(string ss) {
    string ss1 = ss.substr(0,ss.size()/2);
    string ss2 = ss.substr(ss.size()/2+(ss.size()&1),ss.size());
    reverse(all(ss2));
    return ss1==ss2;
}
string s;
bool func(string ss) {
    rep(i,s.size()+1) {
        string t = s;
        t.insert(i,ss);
        if(ok(t)) {
            cout<<t<<endl;
            return true;
        }
    }
    return false;
}
int main() {
    cin>>s;
    int mid = s.size()/2;
    if(ok(s)) {
        stringstream ss;
        ss<<s[mid];
        s.insert(mid,ss.str());
        cout<<s<<endl;
        return 0;
    }
    else {
        rep(i,26) {
            char c = 'a'+i;
            stringstream ss;
            ss<<c;
            if(func(ss.str())) {
                return 0;
            }
        }
    }
    cout<<"NA"<<endl;
    return 0;
}

