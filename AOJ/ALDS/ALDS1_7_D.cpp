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

int n,pos;
vector<int> pre,in,post;

void rec(int l,int r) {
    if(l>=r) return;
    int root=pre[pos++];
    int m=distance(in.begin(),find(all(in),root));
    rec(l,m);
    rec(m+1,r);
    post.pb(root);
}
void solve() {
    pos=0;
    rec(0,pre.size());
    rep(i,n) printf("%d%c",post[i],i==n-1?'\n':' ');
}


int main() {
    int k;
    cin>>n;
    rep(i,n) {
        cin>>k;
        pre.pb(k);
    }
    rep(i,n) {
        cin>>k;
        in.pb(k);
    }
    solve();
    return 0;
}

