#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

string ss;
int str_to_i(string ss_) {
    //cout<<ss_<<endl;
    int ret=0;
    istringstream is(ss_);
    is>>ret;
    return ret;
}
string i_to_str(int n_) {
    ostringstream os;
    os<<n_;
    return os.str();
}

void solve() {
    cin>>ss;
    int ans=0;
    while(ss.size()!=1) {
        int maxi=0;
        string tmp = ss;
        for(int i=1;i<ss.size();i++) {
            int t = str_to_i(ss.substr(0,i))*str_to_i(ss.substr(i));
            if(maxi<=t) {
                maxi=t;
                tmp = i_to_str(t);
            }
        }
        //cout<<"tmp: "<<tmp<<endl;
        ss = tmp;
        ans++;
    }

    cout<<ans<<endl;
}

int main() {
    int n;cin>>n;
    rep(i,n) solve();

    return 0;
}
