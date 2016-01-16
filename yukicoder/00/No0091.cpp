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

int R,G,B;
int cnt(int n) {
    int ret=0;
    if(R>=n) ret++;
    if(G>=n) ret++;
    if(B>=n) ret++;
    return ret;
}
int main() {
    cin>>R>>G>>B;
    int s=min({R,G,B});
    int t=max({R,G,B});
    int m=R^G^B^s^t;
    int ans=s;
    for(int i=s+1;i<=t;i++) {
        int a=cnt(i);
        if(a==1) {
            int b=t-i;
            b/=2;
            b-=i-s;
            b-=i-m;
            if(b>=0) ans=max(ans,i);
        }
        if(a==2) {
            int b=s-i;
            b+=(t-i)/2;
            b+=(m-i)/2;
            if(b>=0) ans=max(ans,i);
        }
        if(a==0) break;
    }
    cout<<ans<<endl;
    return 0;
}

