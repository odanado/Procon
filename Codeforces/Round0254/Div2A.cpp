#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int n,m;
string cell[102];
string ans[102];
int main() {
    cin>>n>>m;
    rep(i,n) cin>>cell[i];
    rep(i,n) {
        string tmp = "";
        rep(j,m) {
            if((i+j)&1) {
                tmp += "B";
            }
            else {
                tmp += "W";
            }
        }
        ans[i]=tmp;
    }
    rep(i,n) rep(j,m) if(cell[i][j]=='-') ans[i][j]='-';

    rep(i,n) { 
        rep(j,m) {
        
            cout<<ans[i][j];
        }
        cout<<endl;
    }


    return 0;
}
