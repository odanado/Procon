#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++) 
const int INF = 100000000;
int n;
int a[100005];
int r[100005];
int l[100005];

int main() {
    cin>>n;
    rep(i,n+1) if(i) cin>>a[i];

    rep(i,n+1) {
        if(!i) continue;
        if(a[i]>a[i-1]) l[i]=l[i-1]+1;
        else l[i]=1;
    }
    for(int i=n;i>0;i--) {
        if(a[i+1]>a[i]) r[i]=r[i+1]+1;
        else r[i]=1;
    }
    int ans = 0;
    rep(i,n+1) {
        if(!i) continue;
        if(a[i-1]+1<a[i+1]) {
            ans = max(ans,l[i-1]+1+r[i+1]);
        }
        else {
            ans = max(ans,max(l[i-1],r[i+1])+1);
        }
    }
    cout<<ans<<endl;
    return 0;
}
