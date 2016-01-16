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
    typedef pair<T,T> node_type;
    static const size_t MAX_N = 1 << 17;
    static const int_type INIT_VAL;
    node_type data[2 * MAX_N - 1];
    size_t n;
    SegTree(size_t n__) {
        n=1;
        while(n < n__) n*=2;
        rep(i,2*n-1) data[i]=node_type(INIT_VAL, -INIT_VAL);
    }

    node_type func(node_type node1, node_type node2) {
        return node_type(min(node1.first, node2.first), max(node1.second, node2.second));
    }

    void update(size_t k, int_type a) {
        k+=n-1;
        data[k]=node_type(a, a);
        while(k>0) {
            k=(k-1)/2;
            data[k]=func(data[k*2+1],data[k*2+2]);
        }
    }

    node_type query(size_t a,size_t b,size_t k,size_t l,size_t r) {
        if(r<=a || b<=l) return node_type(INIT_VAL, -INIT_VAL);
        if(a<=l && r<=b) return data[k];
        else {
            node_type vl = query(a,b,k*2+1,l,(l+r)/2);
            node_type vr = query(a,b,k*2+2,(l+r)/2,r);
            return func(vl,vr);
        }
    }
    node_type query(size_t a,size_t b) {
        return query(a,b,0,0,n);
    }
};

template<class T>
const typename SegTree<T>::int_type SegTree<T>::INIT_VAL = (SegTree<T>::int_type(1) << 20) - 1;


bool isKado(int a,int b,int c) {
    if(a==b) return false;
    if(b==c) return false;
    if(c==a) return false;
    vector<int> vec;
    vec.pb(a);
    vec.pb(b);
    vec.pb(c);
    sort(all(vec));
    return vec[1]==a||vec[1]==c;
}
string to_s(P p) {
    stringstream ss;
    ss << "(";
    ss << p.fr;
    ss << ", ";
    ss << p.sc;
    ss << ")";
    return ss.str();
}
bool isKado(vector<int> vec,int i,int j,int k) {
    vector<P> v;
    v.push_back(P(i,vec[i]));
    v.push_back(P(j,vec[j]));
    v.push_back(P(k,vec[k]));
    sort(all(v));
    //cout<<__LINE__<<": "<<to_s(v[0])<<", "<<to_s(v[1])<<", "<<to_s(v[2])<<endl;
    return isKado(v[0].sc,v[1].sc,v[2].sc);
}

double func(vector<int> E) {
    SegTree<int> seg(E.size());

    rep(i,E.size()) seg.update(i, E[i]);
    int sum=0;
    int cnt=0;
    rep(i,E.size()) rep(j,E.size()) if(i<j) {
        int t=0;
        int A=E[i],B=E[j];
        if(E[i] < E[j]) {
            int x = seg.query(0,i).second;
            if(x>A) t=max(x,B);

            auto y = seg.query(i+1,j);
            if(y.first < A) t=max(t,B);
            if(y.second > B) t=max(t,y.second);


           int z = seg.query(j+1,E.size()).first;
           if(z < B) t = max(t, B);
        }
        if(A>B) {
            int x = seg.query(0,i).first;
            if(x<A) t=max(t,A);

            auto y = seg.query(i+1,j);
            if(y.second > A) t = max(t, y.second);
            if(y.first < B) t = max(t, A);

            int z = seg.query(j+1,E.size()).second;
            if(z > B) t = max(t, max(z,A));
        }
        sum+=t;
        cnt++;
    }
    //cout<<sum<<", "<<cnt<<endl;

    return 1.0*sum/cnt;
}
int N,M;
vector<int> E[802];
int main() {
    cin>>N>>M;
    double maxi=0;
    int ans=0;
    rep(i,M) rep(j,N) {
        int t;
        cin>>t;
        E[i].push_back(t);
    }
    rep(i,M) {
        double t=func(E[i]);
        //cout<<i<<": "<<t<<endl;
        if(maxi<t) {
            maxi=t;
            ans=i;
        }
    }
    cout<<ans<<endl;

    return 0;
}

