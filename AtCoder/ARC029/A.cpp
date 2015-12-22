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

int N;
int t[4];

int main() {
    cin>>N;
    int ans = INF;
    rep(i,N) cin>>t[i];
    if(N==1) {
        ans = t[0];
    }
    else if(N==2) {
        ans = max(t[0],t[1]);
    }
    else if(N==3) {
        rep(i,3) rep(j,3) rep(k,3) {
            if(i==j || i==k) continue;
            if(j==i || j==k) continue;
            if(k==i || k==j) continue;
            ans = min(ans,max(t[i],t[j]+t[k]));


        }
    }
    else {
        rep(i,4) rep(j,4) rep(k,4) rep(l,4) {
            if(i==j || i==k || i==l) continue;
            if(j==k || j==l || k==i) continue;
            if(k==i || k==j || k==l) continue;
            if(l==i || l==j || l==k) continue;

            ans = min(ans,max(t[i]+t[j],t[k]+t[l]));
            ans = min(ans,max(t[i],t[j]+t[k]+t[l]));
        }


    }
    cout<<ans<<endl;
    return 0;
}

