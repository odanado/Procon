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

template<class T,T P>
struct int_mod {
    typedef T int_type;
    T value;
    int_mod(int_type value) : value(((value%P)+P)%P) {
    }

    int_mod<T,P> mod_pow(int_mod<T,P> a,int_type n,int_type mod) {
        int_mod<T,P> ret = 1;
        while(n) {
            if(n & 1) {
                ret*=a;
            }
            a*=a;
            n>>=1;
        }

        return ret;
    }

    const int_mod<T,P> operator+(const int_mod<T,P> &rhs) const {
        return (value+rhs.value)%P;
    }
    const int_mod<T,P> operator-(const int_mod<T,P> &rhs) const {
        return ((value-rhs.value)%P+P)%P;
    }
    const int_mod<T,P> operator*(const int_mod<T,P> &rhs) const {
        return (value*rhs.value)%P;
    }
    const int_mod<T,P> operator/(const int_mod<T,P> &rhs) {
        return ((*this)*mod_pow(rhs,P-2,P));
    }
    const int_mod<T,P> operator+(const int_type &v) const {
        return (value+int_mod<T,P>(v))%P;
    }
    const int_mod<T,P> operator-(const int_type &v) const {
        return ((value-int_mod<T,P>(v))%P+P)%P;
    }
    const int_mod<T,P> operator*(const int_type &v) const {
        return (value*int_mod<T,P>(v))%P;
    }
    const int_mod<T,P> operator/(const int_type &v) {
        return ((*this)*mod_pow(int_mod<T,P>(v),P-2,P))%P;
    }
    
    int_mod<T,P>& operator+=(const int_mod<T,P> &rhs) {
        value=value+rhs.value;
        return *this;
    }
    int_mod<T,P>& operator-=(const int_mod<T,P> &rhs) {
        value=value-rhs.value;
        return *this;
    }
    int_mod<T,P>& operator*=(const int_mod<T,P> &rhs) {
        value=value*rhs.value;
        return *this;
    }
    int_mod<T,P>& operator/=(const int_mod<T,P> &rhs) {
        value=value/rhs.value;
        return *this;
    }
};

int main() {
    int_mod<ll,10000007> a(21+35-35*35-21*35);
    int_mod<ll,10000007> b(35*35+35+21);
    a=a/b;
    cout<<a.value<<endl;
    return 0;
}

