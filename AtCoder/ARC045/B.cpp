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

template<class T>
struct SegTree {
    typedef T int_type;
    static const size_t MAX_N = 1 << 20;
    static const int_type INIT_VAL = (int_type(1)<<31)-1;
    int_type data[2 * MAX_N - 1];
    size_t n;
    SegTree(size_t n__) {
        n=1;
        while(n < n__) n*=2;
        rep(i,2*n-1) data[i]=INIT_VAL;
    }
    void update(size_t k,int_type a) {
        k+=n-1;
        data[k]=a;
        while(k>0) {
            k=(k-1)/2;
            data[k]=min(data[k*2+1],data[k*2+2]);
        }
    }

    int_type query(size_t a,size_t b,size_t k,size_t l,size_t r) {
        if(r<=a || b<=l) return INIT_VAL;
        if(a<=l && r<=b) return data[k];
        else {
            int_type vl = query(a,b,k*2+1,l,(l+r)/2);
            int_type vr = query(a,b,k*2+2,(l+r)/2,r);
            return min(vl,vr);
        }
    }
    int_type query(size_t a,size_t b) {
        return query(a,b,0,0,n);
    }
};
int N,M;
int s[300005],t[300005];
ll a[300005];

int main() {
    cin>>N>>M;
    rep(i,M) scanf("%d %d",s+i,t+i);
    rep(i,M) {
        a[s[i]]++;
        a[t[i]+1]--;
    }
    rep(i,N+1) if(i) a[i]+=a[i-1];
    SegTree<ll> seg(300005);

    rep(i,N+1) if(i) seg.update(i,a[i]);
    vector<int> ans;
    rep(i,M) {
        if(seg.query(s[i],t[i]+1)>1) ans.pb(i);
    }
    cout<<ans.size()<<endl;
    rep(i,ans.size()) cout<<ans[i]+1<<endl;
    return 0;
}

