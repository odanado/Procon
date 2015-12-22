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

bool is_left(int a) {
    if(a==1) return true;
    if(a==4) return true;
    if(a==7) return true;
    return false;
}
bool is_center(int a) {
    if(a==8) return true;
    if(a==2) return true;
    return false;
}
bool is_right(int a) {
    if(a==3) return true;
    if(a==6) return true;
    if(a==9) return true;
    return false;
}

bool ok(int l,int r) {
    if(is_left(l)) return true;
    if(is_right(r)) return true;
    if(is_right(r) && is_right(l)) return true;
    if(is_left(r) && is_left(l)) return true;
    if(is_center(r) && is_center(l)) return true;
    if(is_center(l) && is_right(r)) return true;
    if(is_center(r) && is_left(l)) return true;
    // cout<<"ok : "<<l<<","<<r<<endl;
    return false;

}

int solve1(int a) {
    int ans = 0;
    int r,l;
    r=l=0;
    rep(i,str.size()) {
        int step = str[i] - '0';
        if(i==0) {
            if(a==1) l=step;
            else r=step;
            a^=1;
            continue;
        }
        if(a==1) {
            if(ok(step,r)) {
                l=step;
                a^=1;
            }
            else {
                r=step;
                ans++;
            }
        }
        else {
            if(ok(l,step)) {
                r = step;
                a^=1;
            }
            else {
                l=step;
                ans++;
            }
        }
    }
    // cout<<"ans = "<<ans<<endl;
    return ans;

}

void solve() {
    int l = str[0]-'0';
    int r = str[1]-'0';
    int ans = min(solve1(0),solve1(1));
    cout<<ans<<endl;
}

int main() {
    // cout<<ok(4,2)<<endl;
    // cout<<ok(7,1)<<endl;
    // cout<<ok(6,2)<<endl;
    while(cin>>str) {
        if(str=="#") break;
        solve();

    }
    return 0;
}

