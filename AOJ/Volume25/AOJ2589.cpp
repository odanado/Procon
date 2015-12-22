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

string input;

ll lcm(ll a, ll b) {
    return a/__gcd(a,b)*b;
}

struct Q {
    ll a,b;
    Q(ll a=1,ll b=1) : a(a), b(b) { }

    Q operator+(const Q& obj) {

        ll t = lcm(this->b,obj.b);
        this->a = t/this->b*this->a + t/obj.b*obj.a;
        this->b=t;

        return *this;
    }

    void tuning() {
        if(this->a<0) this->a*=-1;
        if(this->b<0) this->b*=-1;
        ll g = __gcd(this->a,this->b);
        this->a/=g;
        this->b/=g;
    }

};

void print(double a) {
    int cnt=1;
    while(ceil(a)!=(int)a) {
        cnt<<=1;
        a*=2;
    }
    if(cnt==1) {
        cout<<a<<endl;
    }
    else {
        cout<<a<<"/"<<cnt<<endl;
    }
}

void solve() {
    string s="";
    rep(i,input.size()) {
        if(input[i]=='n') {
            i+=4;
            s+="n";
        }
        else {
            i+=3;
            s+="w";
        }
    }
    int n=s.size();
    Q a;
    if(s[n-1]=='n') a=Q(0,1);
    else a=Q(90,1);

    rep(i,n-1) {
        if(s[i]=='n') {
            a = a + Q(-90,(1LL<<(n-i-1)));
        }
        else {
            a = a + Q(90,(1LL<<(n-i-1)));
        }

    }
    a.tuning();
    if(a.b==1) cout<<a.a<<endl;
    else cout<<a.a<<"/"<<a.b<<endl;

}

int main() {
    while(cin>>input) {
        if(input=="#") break;
        solve();
    }
    return 0;
}

