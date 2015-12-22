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
#include <array>

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

typedef vector<array<int,3>> Board;
int b[2][3];
int c[3][2];
inline P calc(const Board &vec) {
    /*
    rep(i,3) {
        rep(j,3) cout<<vec[i][j];
        cout<<endl;
    }
    cout<<endl;
    */

    P ret=P(0,0);
    rep(i,2) rep(j,3) {
        if(vec[i][j]==vec[i+1][j]) {
            ret.fr+=b[i][j];
        }
        else ret.sc+=b[i][j];
    }
    rep(i,3) rep(j,2) {
        if(vec[i][j]==vec[i][j+1]) {
            ret.fr+=c[i][j];
        }
        else ret.sc+=c[i][j];
    }

    return ret;
}
P dfs(Board &vec,int cnt) {
    if(cnt==9) return calc(vec);
    Board next=vec;
    P maxi=P(0,0);
    rep(i,3) rep(j,3) {
        if(vec[i][j]!=0) continue;
        if(cnt%2==0) vec[i][j]=1;
        else vec[i][j]=2;
        P t=dfs(vec,cnt+1);
        if(cnt%2==0) {
            if(maxi.fr<t.fr) {
                maxi=t;
                next=vec;
            }
        }
        else {
            if(maxi.sc<t.sc) {
                maxi=t;
                next=vec;
            }
        }
        vec[i][j]=0;
    }

    return dfs(next,cnt+1);
}
int main() {
    rep(i,2) rep(j,3) cin>>b[i][j];
    rep(i,3) rep(j,2) cin>>c[i][j];

    vector<array<int,3>> vec={{0,0,0},{0,0,0},{0,0,0}};
    P ans=dfs(vec,0);

    cout<<ans.fr<<"\n"<<ans.sc<<endl;

    return 0;
}

