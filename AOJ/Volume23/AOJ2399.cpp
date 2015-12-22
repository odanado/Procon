#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

int N;
int K;
int M[103];
int p[103][103];
int l[103];

bool check(int i_) {
    rep(i,K) {
        rep(j,M[i_]) {
            if(l[i]==p[i_][j]) {
                goto go;
            }
        }
        return false;
go:;
    }
    return true;
}

void solve() {
    rep(i,103) {
        rep(j,103) p[i][j]=0;
        M[i]=0;
        l[i]=0;
    }
    rep(i,N) {
        cin>>M[i];
        rep(j,M[i]) {
            cin>>p[i][j];
        }
    }
    cin>>K;
    rep(i,K) cin>>l[i];

    int ans = 0;
    rep(i,N) {
        if(check(i)) {
            if(ans==0) ans=i+1;
            else ans = -1;
        }
    }
    if(ans==0) ans=-1;
    cout<<ans<<endl;
}

int main() {
    while(cin>>N) {
        if(!N) return 0;
        solve();
    }

    return 0;
}
