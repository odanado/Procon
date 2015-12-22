#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int n;
int a[5003];

int dfs(int l,int r,int h) {
    //cout<<l<<","<<r<<","<<h<<endl;
    int ans = r - l;
    int mini = *min_element(a+l,a+r);
    int ret = mini - h;
    int t = l;

    for(int i=l;i<r;i++) {
        if(a[i]==mini) {
            if(t < i) ret += dfs(t,i,mini);
            t = i + 1;
        }
    }
    if(t < r) ret += dfs(t,r,mini);
    return min(ans,ret);
}
int main() {
    cin>>n;
    rep(i,n) cin>>a[i];
    cout<<dfs(0,n,0)<<endl;

    return 0;
}
