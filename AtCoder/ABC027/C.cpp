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
typedef unsigned long long ll;


bool dfs(ll N,ll a,int p) {
    if(a>N) {
        return p^1;
    }
    if(p==0) {
        return dfs(N,a*2,p^1) || dfs(N,a*2+1,p^1);
    }
    else {
        return dfs(N,a*2,p^1) && dfs(N,a*2+1,p^1);
    }
}

void solve(ll N) {
    if(dfs(N,1,0)) cout<<"Takahashi"<<endl;
    else cout<<"Aoki"<<endl;
}

ll N;
int main() {
    cin>>N;
    if(N==1) {
        cout<<"Aoki"<<endl;
        return 0;
    }
    ll s=2,a=8;
    while(1) {
        if(s<=N&&N<s+a) break;
        s+=a;
        a*=4;
    }
    ll t=s+a;
    // [s,t)
    //cout<<s<<", "<<t<<endl;
    if(N<(s+t)/2) cout<<"Takahashi"<<endl;
    else cout<<"Aoki"<<endl;
    return 0;
}

