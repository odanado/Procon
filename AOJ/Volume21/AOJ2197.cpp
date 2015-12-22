#include<iostream>

using namespace std;

int n;
void solve() {
    int ans=0;
    int add[1003]={};
    for(int i=1;i<n;i++) {
        add[i]=add[i-1]+i;
    }
    for(int l=0;l<n;l++) {
        for(int r=l;r<n;r++) {
            int t = add[r]-add[l];
            if(t<0) t=-t;
            if(n==t) ans++;
        }
    }
    cout<<ans<<endl;
}
int main() {
    while(cin>>n) {
        if(n==0) return 0;
        solve();
    }

    return 0;

}
/* 2014/05/13 AC */

