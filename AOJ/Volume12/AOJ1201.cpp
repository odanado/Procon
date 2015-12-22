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

string board[10];

bool ok(vector<string> &tate, vector<string> &yoko) {
    rep(i,tate.size()) rep(j,tate[i].size()) if(tate[i][j]==yoko[j][i]) return false;
    return true;
}
bool ok(vector<int> &tate, vector<int> yoko) {
    rep(i,5) rep(j,5) {
        if(((tate[i]>>j)&1) == ((yoko[j]>>i)&1)) return false;
    }
    return true;
}
inline unsigned int bitrev(unsigned int x) {
    x=(x&0xaaaaaaaa)>>1|(x&0x55555555)<<1;
    x=(x&0xcccccccc)>>2|(x&0x33333333)<<2;
    x=(x&0xf0f0f0f0)>>4|(x&0x0f0f0f0f)<<4;
    x=(x&0xff00ff00)>>8|(x&0x00ff00ff)<<8;
    return (x&0xffff0000)>>16|(x&0x0000ffff)<<16;
}

void show(vector<string> &tate, vector<string> &yoko) {
    rep(i,tate.size()) {
        cout<<tate[i]<<endl;;
    }
    cout<<endl;
    rep(i,5) {
        rep(j,5) cout<<yoko[j][i];
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;
}
void solve() {
    int ans=0;
    vector<int> vec;
    rep(i,10) {
        int t=0;
        rep(j,board[i].size()) if(board[i][j]=='1') t+=1<<j;
        vec.pb(t);
    }
    sort(all(vec));
    vector<int> tate,yoko;
    tate.resize(5);
    yoko.resize(5);
    do {
        rep(i,5) tate[i]=vec[i];
        rep(i,5) yoko[i]=vec[i+5];
        rep(S1,1<<5) {
            rep(i,5) if(S1>>i&1) tate[i]=bitrev(tate[i]);
            rep(S2,1<<5) {
                rep(i,5) if(S2>>i&1) yoko[i]=bitrev(yoko[i]);
                if(ok(tate,yoko)) ans++;
                rep(i,5) if(S2>>i&1) yoko[i]=bitrev(yoko[i]);
            }
            rep(i,5) if(S1>>i&1) tate[i]=bitrev(tate[i]);
        }

    }while(next_permutation(all(vec)));

    cout<<ans/64<<endl;
}
int main() {
    while(1) {
        cin>>board[0];
        if(board[0]=="END") break;
        rep(i,9) cin>>board[i+1];
        solve();

    }
    return 0;
}

