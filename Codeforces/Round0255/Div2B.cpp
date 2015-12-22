#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++) 

string s;
int k;
vector<pair<int,char> > w;
map<char,int> data;
int main() {
    cin>>s;
    cin>>k;
    rep(i,26) {
        int a;
        cin>>a;
        w.push_back(make_pair(-a,'a'+i));
        data['a'+i] = a;
    }
    int maxi = 0;
    sort(w.begin(),w.end());
    rep(i,w.size()) {
        pair<int,char> p = w[i];
        maxi = -p.first;
        break;
    }

    long long ans = 0;
    rep(i,s.size()) {
        ans += data[s[i]] * (i+1);
    }
    rep(i,k) {
        ans += maxi * (i+1+s.size());
    }
    cout<<ans<<endl;
    

    return 0;
}
