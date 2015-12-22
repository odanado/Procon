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

int L[300];
int N;

struct LCG {
    int val;
    int s,a,c;
    int m;
    LCG(int s=0,int a=0, int c=0, int m=1) : 
        val(s), s(s),a(a),c(c), m(m) {}
    int next() {
        val = (val*a+c) % m;
        return val;
    }
    bool operator< (const LCG& l) const {
        if(this->s < l.s) return true;
        else if(this->s > l.s) return false;
        else {
            if(this->a < l.a) return true;
            else if(this->a > l.a) return false;
            else { 
                if(this->c < l.c) return true;
                else if(this->c >= l.c) return false;
            }
        }
        return false;
        /*
        return 
            this->s < l.s ||
            this->a < l.a ||
            this->c < l.c;
*/
    }
};


double func(int s,int a, int c) {
    int ary[256]={};
    double res=0.0;
    LCG lcg(s,a,c,256);

    rep(i,N) {
        ary[(L[i]+lcg.next())%256]++;
    }
    
    rep(i,256) {
        if(ary[i]!=0) res+=(1.0*ary[i]/N)*log2(1.0*ary[i]/N);
    }
    return abs(res);
}

void solve() {
    double mini=INF;
    vector<pair<double,LCG> > ans;
    rep(i,N) cin>>L[i];
    rep(s,16) rep(a,16) rep(c,16) {
        double t = func(s,a,c);
        // if(t==0) printf("%f : %d,%d,%d\n", t, s, a, c);
        ans.pb(mp(t,LCG(s,a,c)));
    }
    sort(all(ans));
    cout<<ans[0].sc.s<<" "<<ans[0].sc.a<<" "<<ans[0].sc.c<<endl;
}

int main() {
    while(cin>>N) {
        if(N==0) break;
        solve();
    }
    return 0;
}

