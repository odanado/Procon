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
ll n,k,w[100005];

bool func(ll P) {
    ll cnt=0;
    ll sum=0;
    rep(i,n) {
        if(w[i]>P) return false;
        if(sum+w[i]>P) {
            sum=0;
            cnt++;
        }
        sum+=w[i];
    }
    return cnt<k;
}

int main() {
    cin>>n>>k;
    rep(i,n) cin>>w[i];

    ll l=0,r=10e18;
    while(r-l>1) {
        ll mid=(l+r)/2;
        if(func(mid)) r=mid;
        else l=mid;
        // cout<<l<<","<<r<<endl;
    }
    cout<<r<<endl;

    return 0;
}

