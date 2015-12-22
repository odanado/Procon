#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

bool check(string ss) {
    if(ss.size() < 6) return false;
    bool is_num,is_c,is_C;
    is_num = is_c = is_C = false;
    rep(i,ss.size()) {
        char c = ss[i];
        if('0'<=c && c<='9') is_num = true;
        if('a'<=c && c<='z') is_c = true;
        if('A'<=c && c<='Z') is_C = true;
    }
    return is_num & is_c & is_C;
}

int main() {
    string ans[2] = {"VALID","INVALID"};
    string ss;cin>>ss;
    cout<<ans[!check(ss)]<<endl;

    return 0;
}
