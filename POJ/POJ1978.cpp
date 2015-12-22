#include <iostream>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int n,r;

void solve() {
    vector<int> hana(n+1);
    rep(i,n+1) if(i) hana[i]=1+n-i; 
    rep(i,r) {
        int p,c;
        cin>>p>>c;
        vector<int> t(p+1);
        rep(i,p) if(i) t[i]=hana[i];
        
        for(int i=p;i<p+c;i++) {
            //cout<<hana[i-p+1]<<","<<hana[i]<<endl;
            hana[i-p+1]=hana[i];
            //cout<<hana[i-p+1]<<","<<hana[i]<<endl;
        }
        //rep(i,n+1) cout<<hana[i]<<endl;
        for(int i=c+1;i<c+p;i++) {
            hana[i]=t[i-c];
        }
        //rep(i,n+1) cout<<hana[i]<<endl;
    }
    //rep(i,n+1) cout<<hana[i]<<endl;

    cout<<hana[1]<<endl;

}


int main() {
    while(cin>>n>>r) {
        if(n+r==0) return 0;
        solve();
    }

    return 0;
}
