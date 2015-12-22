#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int sum1,sum2;
int n;
int main() {
    rep(i,3) {
        int a;
        cin>>a;
        sum1 += a;
    }
    rep(i,3) {
        int b;
        cin>>b;
        sum2 += b;
    }
    cin>>n;
    int cnt = 0;
    cnt += sum1/5;
    if(sum1%5!=0) cnt++;
    cnt += sum2/10;
    if(sum2%10!=0) cnt++;

    if(cnt <= n) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;


    return 0;
}
