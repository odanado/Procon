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

int w;
int a[100005];

struct SegTree {
    static const int MAX_N = 1 << 17;
    static const int INIT_VAL = -1000000009;
    int data[2 * MAX_N - 1];
    int n;
    SegTree(int n__) {
        n=1;
        while(n < n__) n*=2;
        rep(i,2*n-1) data[i]=INIT_VAL;
    }
    void update(int k,int a) {
        k+=n-1;
        data[k]=a;
        while(k>0) {
            k=(k-1)/2;
            data[k]=max(data[k*2+1],data[k*2+2]);
        }
    }

    int query(int a,int b,int k,int l,int r) {
        if(r<=a || b<=l) return INIT_VAL;
        if(a<=l && r<=b) return data[k];
        else {
            int vl = query(a,b,k*2+1,l,(l+r)/2);
            int vr = query(a,b,k*2+2,(l+r)/2,r);
            return max(vl,vr);
        }
    }
    int query(int a,int b) {
        return query(a,b,0,0,n);
    }
};

int main() {
    cin>>w;
    SegTree segTree(w);

    rep(i,w) cin>>a[i];
    rep(i,w) if(a[i]<0) segTree.update(i,i+a[i]);
    int ans=0;
    cout<<segTree.query(0,w)<<endl;
    return 0;
}

