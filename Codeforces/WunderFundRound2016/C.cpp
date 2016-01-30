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
vector<P> vec;
map<P,int> ids;
vector<int> ans;
double dist(P p1,P p2) {
    return sqrt(pow(p1.fr-p2.fr,2)+pow(p1.sc-p2.sc,2));
}
bool ok(P p1, P p2, P p3) {
    P p;
    p.fr=p1.fr-p2.fr;
    p.sc=p1.sc-p2.sc;
    if(p.fr==0) {
        return p3.fr!=p1.fr;
    }
    double a=1.0*p.sc/p.fr;
    double b=p1.sc-p1.fr*a;

    return p3.sc!=a*p3.fr+b;
}
void f() {
    rep(i,n-2) {
        //cout<<ids[vec[i]]<<", "<<ids[vec[i+1]]<<", "<<ids[vec[i+2]]<<endl;
        if(ok(vec[i],vec[i+1],vec[i+2])) {
            ans.pb(ids[vec[i]]);
            ans.pb(ids[vec[i+1]]);
            ans.pb(ids[vec[i+2]]);
            return;
        }
    }
}
int main() {
    cin>>n;
    rep(i,n) {
        P p;
        cin>>p.fr>>p.sc;
        ids[p]=i+1;
        vec.pb(p);
    }
    sort(all(vec));

    f();

    rep(i,ans.size()) printf("%d%c",ans[i],i+1==ans.size()?'\n':' ');
    return 0;
}

