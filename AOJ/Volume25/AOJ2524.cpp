#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

string ss;
int ans;

int to_int(string ss) {
    if(ss=="") return 0;
    int ret;
    istringstream is(ss);
    is >> ret;
    return ret;
}

void f(int n) {

    string ss1 = ss.substr(0,n);
    string ss2 = ss.substr(n,ss.size());

    //cout<<ans<<","<<ss1<<","<<ss2<<endl;
    if(ss2.size()!=0 && ss2[0] == '0') return;

    int x2 = to_int(ss1) + to_int(ss2);
    int y2 = to_int(ss2) - to_int(ss1);
    if((x2&1)) return;
    int x = x2 / 2;
    int y = y2 / 2;
    if(x >= 0 && y >= 0) ans++;

}

int main() {
    cin>>ss;
    rep(i,ss.size()) f(i);
    cout<<ans<<endl;

    return 0;
}
