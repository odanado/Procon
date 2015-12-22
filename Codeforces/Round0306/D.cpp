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

void push(vector<P> &ret, P p) {
    if(find(all(ret),P(p.sc,p.fr))==ret.end()) {
        ret.pb(p);
    }
}

void make_graph(vector<P> &ret,int s,int n) {
    rep(i,n) if(i) push(ret,P(s,i+s));
    rep(i,n) if(i) rep(j,n) if(i<j&&i!=j&&((i)%2==0||abs(i-j)!=1)) {
        push(ret,P(i+s,j+s));
    }
    rep(i,n) if(i) {
        push(ret,P(i+s,n+s));
        push(ret,P(i+s,n+1+s));
    }
    push(ret,P(n+s,n+1+s));

}

int main() {
    int k;
    cin>>k;
    if(k%2==0) {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    if(k==1) {
        cout<<"2 1"<<endl;
        cout<<"1 2"<<endl;
        return 0;
    }
    vector<P> ans;
    ans.pb(P(1,k+3));
    make_graph(ans,1,k);
    make_graph(ans,k+3,k);

    printf("%d %d\n",2*k+4,ans.size());
    for(auto &e : ans) {
        printf("%d %d\n",e.fr,e.sc);
    }
    return 0;
}

