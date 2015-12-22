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

bool binary_search(int *a,int n,int x) {
    int l=0,r=n;
    while(r-l>0) {
        int mid = (l+r)/2;
        if(a[mid] < x) l=mid+1;
        else if(a[mid] == x) return true;
        else r=mid;
    }
    // cout<<l<<","<<r<<endl;
    return false;
}

int n;
int S[100005];
int q;
int main() {
    int ans=0;
    cin>>n;
    rep(i,n) cin>>S[i];
    cin>>q;
    rep(i,q) {
        int t;
        cin>>t;
        if(binary_search(S,n,t)) ans++;
    }
    cout<<ans<<endl;
    return 0;
}

