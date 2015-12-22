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

struct Node {int p,l,r;};

const int NIL=-1;
Node T[100005];
int n,D[100005];

void print(int u) {
    printf("node %d: parent = %d, depth = %d, ",u,T[u].p,D[u]);

    if(T[u].p==NIL) printf("root,");
    else if(T[u].l==NIL) printf("leaf,");
    else printf("internal node,");

    printf(" [");
    
    for(int i=0,c=T[u].l;c!=NIL;i++,c=T[c].r) {
        if(i) printf(", ");
        printf("%d",c);
    }
    printf("]\n");
}

int rec(int u,int p) {
    D[u]=p;
    // 右は兄妹,左は子
    if(T[u].r!=NIL) rec(T[u].r,p);
    if(T[u].l!=NIL) rec(T[u].l,p+1);
}

int main() {
    int n,r;
    cin>>n;
    rep(i,n) T[i].p=T[i].l=T[i].r=NIL;

    rep(i,n) {
        int v,d,l;
        cin>>v>>d;
        rep(j,d) {
            int c;
            cin>>c;
            if(j==0) T[v].l=c;
            else T[l].r=c;
            l=c;
            T[c].p=v;
        }
    }
    rep(i,n) if(T[i].p==NIL) r=i;
    rec(r,0);
    rep(i,n) print(i);
    return 0;
}

