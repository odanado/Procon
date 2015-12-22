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


bool ok(int p,int q,int m,int n) {
    int t1=m*m+n*n;
    if(t1<=0) return false;
    int t2=m*p+n*q;
    int t3=m*q-n*p;
    return (t2%t1==0)&&(t3%t1==0);
}
void solve() {
    int cnt=0;
    int p,q;
    cin>>p>>q;
    int t=p*p+q*q;
    rep(m,sqrt(t)+1) rep(n,sqrt(t)+1) {
        if(ok(p,q,m,n)) {
            // cout<<m<<","<<n<<endl;
            cnt++;
        }
    }
    // cout<<cnt<<endl;
    if(cnt*2<=8) cout<<"P"<<endl;
    else cout<<"C"<<endl;
}

int main() {
    int q;
    cin>>q;
    while(q-->0) {
        solve();
    }
    return 0;
}

