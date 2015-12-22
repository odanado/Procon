#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

string s,t;
bool check1() {
    int a1[26]={};
    int a2[26]={};
    rep(i,s.size()) a1[s[i]-'a']++;
    rep(i,t.size()) a2[t[i]-'a']++;
    rep(i,26) if(a1[i]!=a2[i]) return false;
    return true;
}
bool check2() {
    rep(i,t.size()) if(s.find(t[i])==string::npos) return true;
    return false;
}
bool check3() {
    int a1[26]={};
    int a2[26]={};
    rep(i,s.size()) a1[s[i]-'a']++;
    rep(i,t.size()) a2[t[i]-'a']++;
    rep(i,26) if(a1[i]<a2[i]) return false;
    return true;

}
bool check4() {
    int j=0;
    rep(i,s.size()) {
        if(j<t.size() && s[i]==t[j]) j++;
        if(j==t.size()) return true;
    }
    return false;
}
int main() {
    cin>>s>>t;
    if(s.size() < t.size()) {
        cout<<"need tree"<<endl;
        return 0;
    }

    if(s.size() == t.size()) {
        if(check1()) cout<<"array"<<endl;
        else cout<<"need tree"<<endl;
    }
    else {
        if(s.find(t)!=string::npos) cout<<"automaton"<<endl;
        else if(check4()) cout<<"automaton"<<endl; 
        else if(check3()) cout<<"both"<<endl;
        else cout<<"need tree"<<endl;
    }

    return 0;
}
