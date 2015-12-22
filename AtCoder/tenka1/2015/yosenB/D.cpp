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

inline int cnv(char c) {
    if(c=='O') return '0';
    if(c=='D') return '0';
    if(c=='I') return '1';
    if(c=='Z') return '2';
    if(c=='E') return '3';
    if(c=='h') return '4';
    if(c=='s') return '5';
    if(c=='q') return '6';
    if(c=='L') return '7';
    if(c=='B') return '8';
    if(c=='G') return '9';
    cout<<"c = "<<c<<endl;
    exit(1);
}
inline string cnv(string s) {
    reverse(all(s));
    string ret;
    rep(i,s.size()) {
        ret+=string(1,cnv(s[i]));
    }
    if(ret[0]=='0') {
        ret.insert(1,".");
    }
    return ret;
}

inline bool cmp(string &s1,string &s2) {
    double d1,d2;
    sscanf(cnv(s1).c_str(),"%lf",&d1);
    sscanf(cnv(s2).c_str(),"%lf",&d2);
    return d1<d2;
}


string W[10004];
int main() {
    int D,N;
    cin>>D>>N;
    rep(i,N) cin>>W[i];
    if(N>8) return 0;
    sort(W,W+N);
    string ans="O";
    do {
        rep(S,1<<N) {
            string s;
            int t=0;
            rep(i,N) if(S>>i&1) t+=W[i].size();
            if(t>D) continue;
            rep(i,N) if(S>>i&1) s+=W[i];
            //cout<<s<<endl;
            if(cmp(ans,s)) ans=s;
        }
    }while(next_permutation(W,W+N));

    ans=cnv(ans);
    auto it=ans.end();
    it--;
    while(ans.size()) {
        if(*it=='0') it=ans.erase(it);
        else break;

    }
    cout<<ans<<endl;
    return 0;
}

