#include <iostream>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
int W,H;
int N;
int p[102];
int pos[2];
int ans;
int main() {
    cin>>W>>H;
    cin>>N;
    rep(i,N) cin>>p[i];
    rep(i,N) {
        pos[p[i]]++;
        if(pos[0]<W) {
            ans+=pos[0]==pos[1];
        }
        else if(pos[0]==W-1) {
            // pass
        }
        else if(pos[0]<W+H-2) {
            ans+=pos[0]==pos[1]+2;
        }
        else if(pos[0]==W+H-2) {
            // pass
        }
        else {
            ans+=pos[0]==pos[1]+4;
        }
        //cout<<i<<": "<<pos[0]<<", "<<pos[1]<<" -> "<<ans<<endl;
    }
    cout<<ans<<endl;
    return 0;
}

