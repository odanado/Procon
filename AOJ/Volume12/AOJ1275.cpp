#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++) 
int f(int n, int k) {
    if(n==1) return 0;
    return (f(n-1,k)+k)%n;
}
int main() {
    int n,m,k;
    while(cin>>n>>k>>m) {
        if(n+m+k==0) return 0;
        int t = m-k+1+n;
        t%=n;
        cout<<(f(n,k)+t+n-1)%n+1<<endl;
    }
    return 0;
}
