#include<iostream>
#include<string>

using namespace std;

string str;
string key="qwertasdfgzxcvb";

void solve() {
    bool left=true;
    int ans=0;
    for(int i=0;i<str.size();i++) {
        if(key.find(str[i])!=string::npos) {
            //find!
            if(!left) ans++;
            left=true;
        }
        else {
            //notfind
            if(left) ans++;
            left=false;
        }
    }

    if(key.find(str[0])==string::npos) ans--;
    cout<<ans<<endl;

}

int main() {
    while(cin>>str) {
        if(str=="#") return 0;
        solve();
    }

    return 0;
}

/* 2014/05/14 AC */

