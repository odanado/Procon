#include <algorithm>
#include <functional>
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
int n,m;
vector<int> a,b;
int abs(int a,int b) {
    int t=a-b;
    if(t<0) t=-t;
    return t;
}

int f(int n,int h1,int h2) {
    // printf("[debug] %d %d %d\n",n,h1,h2);
    int t=n-abs(h1-h2);
    return max(h1,h2)+t/2;
}


int main() {
    cin>>n>>m;
    a.reserve(100005);
    b.reserve(100005);
    int ans=0;
    bool flag=false;

    rep(i,m) {
        int x,y;
        cin>>x>>y;
        /*
        if(i==0&&x!=1) {
            a.pb(1);
            b.pb(0);
        }
        */
        a.pb(x);
        b.pb(y);
        /*
        if(i+1==m&&x!=n) {
            a.pb(n);
            b.pb(0);
        }

        */
    }

    ans=max(ans,max(n-a[m-1]+b[m-1],a[0]+b[0]-1));

    rep(i,a.size()-1) {
        int t=a[i+1]-a[i];
        ans=max(ans,b[i]);
        if(t-abs(b[i+1]-b[i])<0) flag=true;
        ans=max(ans,max(b[i],b[i+1])+(t-abs(b[i+1]-b[i]))/2);
    }

    if(!flag) cout<<ans<<endl;
    else cout<<"IMPOSSIBLE"<<endl;


    return 0;
}

