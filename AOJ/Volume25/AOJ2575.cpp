#include<iostream>
#include<algorithm>
#include<string>

using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

string ss;

bool f(int index) {
    string ss1,ss2="AIDUNYAN";

    for(int i=index;i<index+8;i++) {
        ss1+=ss[i];
    }
    sort(ss1.begin(),ss1.end());
    sort(ss2.begin(),ss2.end());

    if(ss1!=ss2) return false;

    ss.replace(index,8,"AIZUNYAN");
    return true;
}

int main() {
    cin>>ss;

    rep(i,ss.size()) {
        if(f(i)) i+=7;
    }
    cout<<ss<<endl;

    return 0;
}
/* 2014/05/28 AC */

