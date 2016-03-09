#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
int N;
int a,b;
int M;
vector<int> x,y,z;
int K;

int rev(int k,int l,int r) {
    if(k<l||r<k) return k;
    int t2=r-k;
    return l+t2;
}

int main() {
    cin>>N;
    cin>>a>>b;
    cin>>M;
    x.resize(M);
    y.resize(M);
    z.resize(M);
    rep(i,M) cin>>x[i]>>y[i]>>z[i];
    rep(i,M) y[i]--,z[i]--;
    cin>>K;
    K--;

    for(int i=M-1;i>=0;i--) {
        if(x[i]==0) {
            K=rev(K,y[i],z[i]);
        }
    }
    int ans=a+b*K;
    rep(i,M) {
        if(K<y[i]||z[i]<K) continue;
        if(x[i]==0) {
            K=rev(K,y[i],z[i]);
        }
        if(x[i]==1) {
            ans++;
        }
        if(x[i]==2) {
            ans/=2;
        }
    }
    cout<<ans<<endl;


    return 0;
}

