#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)


int N;
vector<string> vec;
int number[20];
bool used[20];
string all;

inline int to_i(const string & str) {
    int ret;
    sscanf(str.c_str(),"%d",&ret);
    return ret;
}
int ok() {
    int l_val = 0;
    int r_val = 0;

    rep(i,vec.size()-1) {
        if(number[all.find(vec[i][0])] == 0) return 0;
        int tmp = 0;
        int a = 1; 
        rep(j,vec[i].size()) {
            tmp += number[all.find(vec[i][vec[i].size()-j-1])]*a;
            a *= 10;
        }
        l_val += tmp;
    }
    if(number[all.find(vec[vec.size()-1][0])] == 0) return 0;
    int tmp = 0;
    int a = 1;
    rep(j,vec[vec.size()-1].size()) {
        tmp += number[all.find(vec[vec.size()-1][vec[vec.size()-1].size()-j-1])]*a;
        a *= 10;
    }
    r_val = tmp;

    //cout<<l_val<<","<<r_val<<endl;
    /*
    if(l_val == r_val) {
        int t[20] = {};
        rep(i,all.size()) {
            if(t[number[i]] != 0) return 0;
            t[number[i]]++;
        }
    }
    else return 0;
    */
    //rep(i,all.size()) cout<<number[i]<<",";
    //cout<<endl;
    return l_val == r_val;
}
int dfs(int ind) {
    if(ind == all.size()) {
        return ok();
    }
    //cout<<ind<<","<<number[ind]<<endl;
    int ret = 0;

    rep(i,10) {
        if(used[i]) continue;
        used[i] = true;
        int t = number[ind];
        number[ind]=i;
        //cout<<number[ind]<<endl;
        
        ret += dfs(ind+1);
        used[i] = false;
        //number[ind]=t;
    }
    return ret;
}

void solve() {
    rep(i,20) number[i] = 0;
    rep(i,20) used[i] = false;
    
    all = "";
    vec.resize(N);
    rep(i,N) {
        string ss;
        cin>>ss;
        all += ss;
        vec[i] = ss;
    }
    sort(all.begin(),all.end());
    all.erase(unique(all.begin(),all.end()),all.end());
    
    int ans = 0;
    rep(i,10) {
        number[0] = i;
        used[i] = true;
        ans += dfs(1);
        used[i] = false;
    }
    cout<<ans<<endl;


    vec.clear();
}

int main() {
    while(cin>>N) {
        if(!N) return 0;
        solve();
    }

    return 0;
}
