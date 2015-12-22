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

int a,b,d;
void update(P &ans,P p) {
    if(ans.fr+ans.sc > p.fr+p.sc) {
        ans=p;
        return;
    }
    if(ans.fr+ans.sc==p.fr+p.sc) {
        if(ans.fr*a+ans.sc*b > p.fr*a+p.sc*b)
           ans=p; 
    }
}
void solve() {
    P ans(INF,INF);
    int g = __gcd(__gcd(a,d),__gcd(b,d));
    a /= g;
    b /= g;
    d /= g;
    //cout<<a<<", "<<b<<", "<<d<<endl;

    rep(x, 50000) {
        int t=(a*x-d);
        if(t<0) continue;
        //if(x < 10) printf("%d %d\n",x, t);
        if(t%b==0) {
            update(ans,P(x,t/b));
        }
    }

    rep(y, 50000) {
        int t=b*y-d;
        if(t<0) continue;
        //if(y < 10) printf("%d %d\n",y,t);
        if(t%a==0) {
            update(ans,P(t/a,y));
        }
    }
    rep(x, 50000) {
        int t=(d-a*x);
        if(t<0) continue;
        //if(x < 10) printf("%d %d\n",x, t);
        if(t%b==0) {
            update(ans,P(x,t/b));
        }
    }
    cout<<ans.fr<<" "<<ans.sc<<endl;


}
int main() {
    while(cin>>a>>b>>d) {
        if(a==0) break;
        solve();
    }
    return 0;
}

