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

char vals['z'];
int A[100005];
int n;
ll cnv(ll base,string &val) {
    ll ret=0;
    ll mul=1;
    reverse(all(val));
    rep(i,val.size()) {
        ret+=mul*vals[val[i]];
        mul*=base;
    }

    return ret;

}
int main() {
    rep(i,10) vals[i+'0']=i;
    rep(i,26) vals[i+'A']=i+10;
    rep(i,26) vals[i+'a']=i+36;
    cin>>n;
    rep(i,n) {
        int p;
        string m;
        cin>>p>>m;
        A[i]=cnv(p,m);
    }
    int ans=0;
    rep(i,n) ans^=A[i];
    if(ans) cout<<"win"<<endl;
    else cout<<"lose"<<endl;
    return 0;
}

