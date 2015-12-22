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

int N,M;
vector<int> p;

vector<int> runlen(const string &s) {
    vector<int> res;
    char c=s[0];
    int cnt=1;
    for(int i=1;i<s.size();i++) {
        if(c==s[i]) cnt++;
        else {
            res.pb(cnt);
            c=s[i];
            cnt=1;
        }
    }
    res.pb(cnt);
    return res;
}
void func(string &s, char c) {
    rep(i,M) {
        rep(j,p[i]) {
            s+=c;
        }
        if(c=='0') c='1';
        else c='0';
    }

}

int f(string s1, string s2) {
    // cout<<s1<<","<<s2<<endl;
    int res=0;
    rep(i,s1.size()) {
        if(s1[i]==s2[i]) continue;
        for(int k=i+1;k<s2.size();k++) {
            if(s1[i]==s2[k]) {
                // cout<<i<<","<<k<<endl;
                res+=k-i;
                swap(s2[i],s2[k]);
                break;
            }
        }
    }
    if(s1!=s2) return INF;
    return res;
}

int main() {
    string s;
    cin>>N>>M;
    rep(i,N) {
        char c;
        cin>>c;
        s+=c;
    }
    rep(i,M) {
        int x;
        cin>>x;
        p.pb(x);
    }
    string s0,s1;

    func(s0,'0');
    func(s1,'1');

    cout<<min(f(s,s0),f(s,s1))<<endl;
    return 0;
}

