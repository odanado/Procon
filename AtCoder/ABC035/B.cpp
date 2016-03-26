#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
using ll = long long;

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

const ll INF=1e9;
const ll MOD=1e9+7;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int x,y;
string S;
int T;
int main() {
    int cnt=0;
    cin>>S>>T;
    rep(i,S.size()) {
        if(S[i]=='?') cnt++;
        else {
            if(S[i]=='L') x--;
            if(S[i]=='R') x++;
            if(S[i]=='U') y++;
            if(S[i]=='D') y--;
        }
    }
    if(T==1) {
        cout<<abs(x)+abs(y)+cnt<<endl;
    }
    else {
        int d=abs(x)+abs(y);
        if(d>cnt) cout<<d-cnt<<endl;
        else cout<<(cnt-d)%2<<endl;
    }
    return 0;
}

