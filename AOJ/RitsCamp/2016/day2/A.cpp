#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
int n,m;
int a[200005];
int b[200005];

int main() {
    cin>>n>>m;
    rep(i,m) cin>>a[i];
    rep(i,m) a[i]--;
    rep(i,200005) b[i]=1e8;
    rep(i,m) b[a[i]]=0;
    rep(i,n) if(i) {
        b[i]=min(b[i],b[i-1]+1);
    }
    for(int i=n-1;i>=0;i--) if(i+1!=n) b[i]=min(b[i],b[i+1]+1);

    int ans=0;
    rep(i,n) ans=max(ans,b[i]);
    cout<<ans<<endl;
    return 0;
}
