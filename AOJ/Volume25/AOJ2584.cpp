#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <climits>

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

const int INF=100000000;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
using namespace std;
typedef pair<int ,int > P;
typedef long long ll;

string s;
string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void f1() {
    s += "Z";
    int cnt = 0;
    for(int i=0; i<s.size(); i++) {
        if(isalpha(s[i])) {
            while(cnt<0) cnt+=26;
            cnt %= 26;
            cnt += s[i]-'A';
            cnt %= 26;

            s[i] = alphabet[cnt];

            cnt = 0;
        }
        else if(s[i] == '+') cnt++;
        else if(s[i] == '-') cnt--;
        else if(s[i] == '?') cnt=0;
    }

    string ret = "";
    rep(i,s.size()-1) {
        if(isalpha(s[i]) || s[i]=='[' || s[i]==']' || s[i]=='?') ret += s[i];
    }
    s = ret;
}

void str_reverse(int s0, int t0) {
    string ret = "";
    for(int i=t0; i>=s0; i--) ret += s[i];

    // cout<<"hoge : "<<ret<<endl;
    // cout<<s.substr(0,s0)<<endl;
    // cout<<s.substr(t0+1,s.size()-t0)<<endl;
    s = s.substr(0,s0) + ret + s.substr(t0+1,s.size()-t0);
}
void f2() {
    stack<int> st;
    rep(i,s.size()) {
        if(s[i] == '[') {
            st.push(i);
        }
        else if(s[i] == ']') {
            int top = st.top();
            st.pop();
            // cout<<top<<","<<i<<endl;
            // cout<<s<<endl;
            str_reverse(top, i);
            // s[top] = '.';
            // s[i] = '.';
            // cout<<s<<endl;
            // s = s.erase(top,1);
            // s = s.erase(i-1,1);
            // cout<<s<<endl;
        }
    }
}

void f3() {
    string ret = "";

    rep(i,s.size()) {
        if(isalpha(s[i])) ret += s[i];
        else if(s[i] == '?') ret += "A";
    }

    s = ret;
}

void solve() {
    f1();
    rep(i,s.size()) {
        if(s[i] == '?') s[i] = 'A';
    }

    f2();
    f3();

    cout<<s<<endl;

}

int main() {
    while(cin>>s) {
        if(s==".") break;
        solve();
    }
    return 0;
}

