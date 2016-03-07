#include <iostream>
#include <string>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

string s;
int main() {
    int N,D;
    cin>>N;
    cin>>s;
    cin>>D;
    int idx=0;
    while(D&&idx<N) {
        if(s[idx]=='0') {
            s[idx]='*';
            D--;
        }
        idx++;
    }
    while(D) {
        if(s[idx]=='1') {
            s[idx]='0';
            D--;
        }
        idx--;
    }
    rep(i,N) if(s[i]=='*') s[i]='1';
    cout<<s<<endl;
    return 0;
}
