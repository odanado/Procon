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

int n,m,k;
P r[5003],c[5003];
int get(int i,int j) {
    P p1=r[i];
    P p2=c[j];
    if(p1.sc>p2.sc) return p1.fr;
    else if(p1.sc<p2.sc) return p2.fr;
    return 0;
}
int main() {
    cin>>n>>m>>k;
    rep(i,5003) r[i]=c[i]=P(0,-1);
    rep(i,k) {
        int t,s,a;
        cin>>t>>s>>a;
        s--;
        if(t==1) {
            r[s]=P(a,i);
        }
        else {
            c[s]=P(a,i);
        }
    }
    rep(i,n) {
        rep(j,m) {
            cout<<get(i,j)<<" ";
        }
        cout<<endl;
    }
    return 0;
}

