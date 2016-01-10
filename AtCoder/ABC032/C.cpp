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

int N,K;
ll a[100005];
int solve1() {
    int ret=0;
    rep(i,N) {
        ll mul=1;
        int j;
        j=i;
        while(1) {
            if(j==N) {
                break;
            }
            if(mul*a[j]>K) break;
            mul*=a[j];
            j++;
        }
        /*
        for(j=i;j<N&&mul*a[j]<=K;j++) {
            mul*=a[j];
        }
        */
        //printf("debug: %d %d\n",i,j);
        ret=max(ret,j-i);
    }

    return ret;
}
int main() {
    cin>>N>>K;
    rep(i,N) cin>>a[i];
    bool f=false;
    rep(i,N) f|=a[i]==0;
    if(f) {
        cout<<N<<endl;
        return 0;
    }
    if(N<=1000) {
        cout<<solve1()<<endl;
        return 0;
    }
    ll mul = 1;
    int s,t;
    s=t=0;
    int ans=0;
    while(s<N&&t<N) {
        t=max(s,t);
        while(t<N&&mul*a[t]<=K) {
            //printf("debug: %d %d\n",t,mul);
            mul*=a[t];
            t++;
        }

        //printf("debug: %d %d %lld\n",s,t,mul);
        if(t<N)
            ans=max(ans,t-s);
        else
            ans=max(ans,t-s);
        if(s!=t)
            mul/=a[s];
        s++;
    }
    cout<<ans<<endl;
    return 0;
}

