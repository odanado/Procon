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

int dx[] = {-1,0,1,1,1,0,-1,-1};
int dy[] = {1,1,1,0,-1,-1,-1,0};

using namespace std;
typedef pair<int ,int > P;
typedef long long ll;

int H,W;
string donut[11];
map<string, int> res;

void dfs(string str,int sy,int sx, int y,int x,int a) {
    int ny = (y+dy[a]+H) % H;
    int nx = (x+dx[a]+W) % W;
    res[str]++;
    if(sy==ny && sx==nx) return;

    dfs(str+donut[ny][nx],sy,sx,ny,nx,a);
}

string cmp(string s1,string s2) {
    if(s1.size() > s2.size()) return  s1;
    else if(s1.size() < s2.size()) return s2;
    else return s1 < s2 ? s1 : s2;
}

void solve() {
    res.clear();
    rep(i,11) donut[i]="";
    rep(i,H) cin>>donut[i];
    rep(y,H) rep(x,W) {
        rep(a,8) {
            string tmp;
            tmp = donut[y][x];
            dfs(tmp,y,x,y,x,a);
        }
    }
    string ans;
    for(const auto &it : res){
        if(it.sc >= 2) {
            ans = cmp(ans,it.fr);
        }
    }
    if(ans.size() <= 2) ans = "0";
    cout<<ans<<endl;
}

int main() {
    while(cin>>H>>W) {
        if(H+W==0) break;
        solve();
    }
    return 0;
}

