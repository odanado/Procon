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
struct StarrySkyTree {
    using int_type = T;
    vector<T> data1;
    vector<T> data2;
    vector<T> lazy;
    int N;
    StarrySkyTree(int n) {
        N=1;
        while(N<n) N<<=1;
        data1.assign(2*N-1, 0);
        data2.assign(2*N-1, 0);
        lazy.assign(2*N-1, 0);
    }
    // [a,b)
    void add(int a,int b, int_type val) {
        //printf("add: [%d,%d) + %lld\n",a,b,val);
        add(a,b,val,0,0,N);
    }
    int_type getMax(int a,int b) {
        return getMax(a,b,0,0,N);
    }
    int_type getMin(int a,int b) {
        return getMin(a,b,0,0,N);
    }

    void add(int a,int b,int_type val, int k,int l,int r) {
        if(r<=a || b<=l) return;
        if(a<=l && r<=b) {
            lazy[k]+=val;
            return;
        }
        add(a,b,val,k*2+1,l,(l+r)/2);
        add(a,b,val,k*2+2,(l+r)/2,r);
        data1[k]=max(data1[k*2+1]+lazy[k*2+1], data1[k*2+2]+lazy[k*2+2]);
        data2[k]=min(data2[k*2+1]+lazy[k*2+1], data2[k*2+2]+lazy[k*2+2]);
    }

    int_type getMax(int a,int b, int k,int l, int r) {
        if(r<=a || b<=l) return -INF;
        if(a<=l && r<=b) return data1[k]+lazy[k];
        int_type lval = getMax(a,b,k*2+1,l,(l+r)/2);
        int_type rval = getMax(a,b,k*2+2,(l+r)/2,r);
        return max(lval, rval)+lazy[k];
    }
    int_type getMin(int a,int b, int k,int l, int r) {
        if(r<=a || b<=l) return INF;
        if(a<=l && r<=b) return data2[k]+lazy[k];
        int_type lval = getMin(a,b,k*2+1,l,(l+r)/2);
        int_type rval = getMin(a,b,k*2+2,(l+r)/2,r);
        return min(lval, rval)+lazy[k];
    }
};


int N;
int S[500005];
int Q;
int main() {
    StarrySkyTree<ll> sst(500005);
    cin>>N;
    rep(i,N) cin>>S[i];
    rep(i,N/2) sst.add(i,i+1,S[i]-S[N-i-1]);
    cin>>Q;
    while(Q--) {
        int x,y,z;
        cin>>x>>y>>z;
        x--,y--;
        if(y<N/2) {
            sst.add(x,y+1,z);
        }
        else if(N/2<x) {
            int a=N-y-1;
            int b=N-x-1;
            sst.add(a,b+1,-z);
        }
        else {
            sst.add(x,N/2,z);
            sst.add(N-y-1,N/2,-z);
        }
        auto a=sst.getMin(0,N/2);
        auto b=sst.getMax(0,N/2);
        if(!a&&!b) cout<<"1"<<endl;
        else cout<<"0"<<endl;
    }
    return 0;
}

