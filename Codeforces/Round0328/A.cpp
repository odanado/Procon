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
using namespace std;
typedef pair<int ,int > P;
typedef long long ll;

string s[8];
int cnt(int y,int x,int dy) {
    int cnt=0;
    while(1) {
        if(y<0||y>=8) break;
        if(s[y][x]!='.') return INF;
        cnt++;
        y+=dy;
    }

    return cnt;
}
int main() {
    int a=INF,b=INF;
    rep(i,8) cin>>s[i];
    rep(y,8) rep(x,8) {
        if(s[y][x]=='W') {
            a=min(a,cnt(y-1,x,-1));
        }
        if(s[y][x]=='B') {
            b=min(b,cnt(y+1,x,1));
        }
    }
    if(a<=b) {
        cout<<"A"<<endl;
    }
    else cout<<"B"<<endl;
    return 0;
}

