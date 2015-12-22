#include<iostream>

#define min(a,b) a<b?a:b
int e;
const int MAX_E = 1000000;
using namespace std;

void solve() {

    int ans=100000000;
    for(int z=0;z*z*z<=MAX_E;z++) {
        for(int y=0;y*y<=MAX_E;y++) {
            int x = e - y*y;
            if(x<0) break;
            x -= z*z*z;
            if(x<0) break;
            ans=min(ans,x+y+z);
        }
    }
    cout<<ans<<endl;

}

int main() {

    while(cin>>e) {
        if(e==0) return 0;
        solve();

    }
    return 0;
}
