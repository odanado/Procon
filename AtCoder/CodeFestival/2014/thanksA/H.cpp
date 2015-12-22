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

int R,C;
string s[300];
bool ok(int x,int y,int w,int h) {
    if(w==0 || h==0) return false;
    if(w==1 || h==1) return false;
    vector<P> vec;
    // printf("[debug] %d,%d,%d,%d\n",x,y,w,h);
    for(int i=x;i<x+w;i++) {
        for(int j=y;j<y+h;j++) {
            // cout<<i<<","<<j<<endl;
            if(i>R || j>C) return false;
            vec.pb(P(i,j));
        }
    }
    int i = vec.size()/2;
    int j = i-1;
    while(j>=0) {
        // printf("[debug] %d,%d <-> %d,%d\n", vec[i].fr, vec[i].sc, vec[j].fr,vec[j].sc);
        // printf("[debug] %c %c\n", s[vec[i].fr][vec[i].sc], s[vec[j].fr][vec[j].sc]);
        if(s[vec[i].fr][vec[i].sc] != s[vec[j].fr][vec[j].sc]) return false;
        i++;
        j--;
    }

    return true;
}
int main() {
    int ans=0;
    cin>>R>>C;
    if(R>50 || C>50) return 0;
    rep(i,R) cin>>s[i];
    //cout<<ok(0,0,2,3)<<endl;
    //cout<<ok(0,8,2,2)<<endl;

    rep(x,R) rep(y,C) rep(w,55) rep(h,55) {
            // printf("[debug] %d,%d,%d,%d\n",x,y,w,h);
        if(ok(x,y,w,h)) {
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}

