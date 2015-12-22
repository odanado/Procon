#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
void f(string &ss,char c) {
    if(c == 'C') {
        char t = ss[0];
        rep(i,ss.size()-1) ss[i] = ss[i+1];
        ss[ss.size()-1] = t;
    }
    else if(c=='J') {
        char t = ss[ss.size()-1];
        for(int i = ss.size()-1; i>=1; i--) ss[i] = ss[i-1];
        ss[0] = t;
    }
    else if(c=='E') {
        string l = ss.substr(0,ss.size()/2);
        string r = ss.substr((ss.size()+1)/2,ss.size()/2);
        string center = "";
            
        if(ss.size()&1) {
            center = ss[ss.size()/2];

        }
        ss = r + center + l;
    }
    else if(c=='A') {
        reverse(ss.begin(), ss.end());
    }
    else if(c=='M') {
        rep(i,ss.size()) {
            if('0'<=ss[i]&&ss[i]<='9') {
                if('9'==ss[i]) ss[i] = '0';
                else ss[i]++;
            }
        }
    }
    else if(c=='P') {
        rep(i,ss.size()) {
            if('0'<=ss[i]&&ss[i]<='9') {
                if('0'==ss[i]) ss[i] = '9';
                else ss[i]--;
            }
        }

    }
}
int main() {
    int n;
    cin>>n;
    rep(i,n) {
        string ss1,ss2;
        cin>>ss1>>ss2;
        reverse(ss1.begin(),ss1.end());
        rep(j,ss1.size()) f(ss2,ss1[j]);
        cout<<ss2<<endl;
    }

    return 0;
}
