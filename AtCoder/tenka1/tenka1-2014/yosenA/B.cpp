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

ll combo(ll a,ll c) {
    double b = 1.0 + floor(c/10.0) * 0.1;
    return a * b;

}
struct Kabu {
    int cnt;
    Kabu() {
        cnt = 0;
    }
    Kabu(int cnt) :
        cnt(cnt) {}
};
Kabu kabu[5];

// n匹投げる
bool ok(int n) {
    int cnt = 0;
    rep(i,5) {
        if(kabu[i].cnt==0) {
            cnt++;
        }
    }
    if(cnt<n) return false;
    rep(i,5) {
        if(kabu[i].cnt==0) {
            kabu[i].cnt=7;
            n--;
        }
        if(n==0) return true;
    }
    return true;
    
}
bool f[2000006];
int main() {
    ll ans = 0;
    ll c = 0;
    string s;
    cin>>s;
    int index=0;
    for(int i=0;i<s.size();i++) {
        cout<<i<<" : ";
        rep(k,5) cout<<kabu[k].cnt;
        cout<<endl;
        if(f[i]) c++;
       if(s[index]=='N') {
           if(ok(1)) {
               ans += combo(10,c);
               rep(j,5) if(kabu[j].cnt!=0) kabu[j].cnt--;
               f[i+4]=true;
               index++;
           }
           else {
               rep(j,5) if(kabu[j].cnt!=0) kabu[j].cnt--;
           }
       }
       else if(s[index]=='C') {
           if(ok(3)) {
               index++;
               ans += combo(50,c);
               rep(j,5) if(kabu[j].cnt!=0) kabu[j].cnt--;
               f[i+4]=true;
               i+=4;
           }
           else {
               rep(j,5) if(kabu[j].cnt!=0) kabu[j].cnt--;

           }
       } 
       else {
           index++;
           rep(j,5) if(kabu[j].cnt!=0) kabu[j].cnt--;
       }
    }
    cout<<ans<<endl;
    return 0;
}

