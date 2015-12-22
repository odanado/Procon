#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int D,N;
int T[202];
struct Shirt {
    int A,B;
    int C;
    Shirt(int A,int B,int C) :
        A(A),B(B),C(C){}
    Shirt() {}
};

Shirt shirt[202];
// i日目にj番目の服を着る
int dp[202][202];
int main() {
    cin>>D>>N;
    rep(i,D) cin>>T[i];
    rep(i,N) {
        int A,B,C;
        cin>>A>>B>>C;
        shirt[i] = Shirt(A,B,C);
    }
    rep(i,D) {
        rep(j,N) {
            rep(k,N) {
                if(!(shirt[k].A<=T[i+1] && T[i+1]<=shirt[k].B)) continue;
                if(!(shirt[j].A<=T[i] && T[i]<=shirt[j].B)) continue;
                dp[i+1][k] = max(dp[i+1][k],dp[i][j] + abs(shirt[k].C-shirt[j].C));
            }
        }
    }
    cout<<(*max_element(dp[D-1],dp[D-1]+N))<<endl;
    return 0;
}
