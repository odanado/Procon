#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++) 
int N,L;
struct Data {
    int l,r,c;

    Data(int l,int r,int c) :l(l),r(r),c(c){};
    Data() {};
    bool operator<(const Data& d) const {
        return d.l > l;
    }
};
Data data[100005];
int dp[3003];

int main() {
    rep(i,3003) dp[i] = 100000000;
    cin>>N>>L;
    rep(i,N) {
        int a,b,c;
        cin>>a>>b>>c;
        data[i].l = a;
        data[i].r = b;
        data[i].c = c;
    }

    sort(data,data+N);
    dp[0] = 0;
    rep(i,N) {
        for(int k=data[i].l;k<=data[i].r;k++) {
            dp[k] = min(dp[k], dp[data[i].l]+data[i].c);
        }
    }

    cout<<dp[L]<<endl;
    return 0;
}
