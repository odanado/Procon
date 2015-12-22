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

const int NIL=-1;

struct Node{int parent,left,right;};
Node T[10004];
int n,D[10004],H[10004];

void setDepth(int u,int d) {
    if(u==NIL) return;
    D[u]=d;
    setDepth(T[u].left,d+1);
    setDepth(T[u].right,d+1);
}

int setHeight(int u) {
    int h1=0,h2=0;
    if(T[u].left!=NIL) h1=setHeight(T[u].left)+1;
    if(T[u].right!=NIL) h2=setHeight(T[u].right)+1;

    return H[u]=max(h1,h2);
}

int getSibling(int u) {
    if(T[u].parent==NIL) return NIL;
    if(T[T[u].parent].left!=u && T[T[u].parent].left!=NIL) return T[T[u].parent].left;
    if(T[T[u].parent].right!=u && T[T[u].parent].right!=NIL) return T[T[u].parent].right;
    return NIL;
}

void print(int u) {
    printf("node %d: ",u);
    printf("parent = %d, ",T[u].parent);
    printf("sibling = %d, ",getSibling(u));
    int deg=0;
    if(T[u].left!=NIL) deg++;
    if(T[u].right!=NIL) deg++;
    printf("degree = %d, ",deg);
    printf("depth = %d, ",D[u]);
    printf("height = %d, ",H[u]);

    if(T[u].parent == NIL) {
        printf("root\n");
    }
    else if(T[u].left==NIL&&T[u].right==NIL) {
        printf("leaf\n");
    }
    else {
        printf("internal node\n");
    }

}

int main() {
    int v,l,r;
    int root=0;
    cin>>n;
    rep(i,n) T[i].parent=NIL;
    rep(i,n) {
        cin>>v>>l>>r;
        T[v].left=l;
        T[v].right=r;
        if(l!=NIL) T[l].parent=v;
        if(r!=NIL) T[r].parent=v;
    }
    rep(i,n) if(T[i].parent==NIL) root=i;
    setDepth(root,0);
    setHeight(root);
    rep(i,n) print(i);
    return 0;
}

