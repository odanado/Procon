#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
int main() {
    int n,a,b;
    cin>>n>>a>>b;
    int t = (n-5)*a;
    if(t<0) t=0;
    cout<<t+b*min(n,5)<<endl;

    return 0;
}
