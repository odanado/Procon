#include<bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
int k;
int c[4];

int f(int val) {
    int cnt = 0;
    int values[] = {500,100,50,10};
    rep(i,4) {
        int t = val/values[i];

        val -= (t*values[i]);
        cnt += t;
    }
    return cnt;
    
}

void solve() {
    int sum=0;
    rep(i,4) cin>>c[i],sum+=c[i];
    int mini = 10000;
    int ans[4] = {};
    
    rep(i1,c[0]+1) rep(i2,c[1]+1) rep(i3,c[2]+1) rep(i4,c[3]+1) {
        int t = i1*10+i2*50+i3*100+i4*500;
        t-=k;

        if(t<0) continue;
        
        int tt = sum + f(t) - i1 - i2 - i3 - i4;
        if(tt < mini) {
            mini = tt;
            ans[0] = i1;
            ans[1] = i2;
            ans[2] = i3;
            ans[3] = i4;
        }
       
    }

    if(ans[0]!=0) cout<<"10 "<<ans[0]<<endl;
    if(ans[1]!=0) cout<<"50 "<<ans[1]<<endl;
    if(ans[2]!=0) cout<<"100 "<<ans[2]<<endl;
    if(ans[3]!=0) cout<<"500 "<<ans[3]<<endl;

}

int main() {
    int f=1;
    while(cin>>k) {
        if(k==0) return 0;
        if(f) {
            f=0;
        }
        else cout<<endl;
        solve();
    }

    return 0;
}
