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

bool is_prime(int n) {
    for(int i=2;i*i<=n;i++) {
        if(n%i==0) return false;
    }
    return true;
}

int pi(int n) {
    for(int i=n;i>=2;i--) if(is_prime(i)) return i;
    return -1;
}

bool palindromic(int n) {
    stringstream ss;
    ss<<n;
    string s=ss.str();
    rep(i,s.size()/2) {
        if(s[i]!=s[s.size()-1-i]) return false;
    }

    return true;
}

int rub(int n) {
    for(int i=n;i>=1;i--) if(palindromic(i)) {
        return i;
    }
    return -1;
}

int main() {
    int p,q;
    cin>>p>>q;
    int ans=0;
    rep(i,1000) {
        if(q*pi(i)<=p*rub(i)) ans=max(i,ans);
    }
    cout<<ans<<endl;
    return 0;
}

