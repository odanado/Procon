#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

string ss;
int not_[2] = {1,0};
int and_[2][2] = { {0,0},{0,1}};
int or_[2][2] = { {0,1},{1,1}};
int imp_[2][2] = { {1,1},{0,1}};
int bit;

int dfs(const string& formula,int& pos) {
    //cout<<formula<<","<<pos<<endl;
    int ret;
    if(formula[pos] =='T') ret = 1;
    else if(formula[pos] =='F') ret = 0;

    else if(formula[pos] == '-') return not_[dfs(formula,++pos)];
    else if('a' <= formula[pos] && formula[pos] <= 'k') ret = (bit >> (formula[pos]-'a')) &1;
    else if(formula[pos] == '(') {
        ret = dfs(formula, ++pos);
        if(formula[pos] == '+') ret = or_[ret][dfs(formula,++pos)];
        else if(formula[pos] == '*') ret = and_[ret][dfs(formula,++pos)];
        else if(formula[pos] == '-') {
            pos++;
            ret = imp_[ret][dfs(formula,++pos)];
        }
    }
    pos++;
    return ret;

}

void solve() {
    string l = ss.substr(0,ss.find("="));
    string r = ss.substr(ss.find("=")+1);
    int pos=0;
    bool flag = true;
    for(bit = 0; bit < (1<<11); bit++) {
        pos = 0;
        int tmp1 = dfs(l,pos);
        pos = 0;
        int tmp2 = dfs(r,pos);
        if(tmp1!=tmp2) flag = false;
    }
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main() {
    while(cin>>ss) {
        if(ss=="#") return 0;
        solve();
    }


    return 0;
}
