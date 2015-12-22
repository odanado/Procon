#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++) 
int n,p;

int main() {
    set<int> S;
    cin>>p>>n;
    rep(i,n) {
        int x;
        cin>>x;
        if(S.find(x%p) != S.end()) {
            cout<<i+1<<endl;
            return 0;
        }
        S.insert(x%p);
    }
    cout<<"-1"<<endl;


    return 0;
}
