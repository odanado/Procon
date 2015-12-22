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

int h,w,n;
void dump(vector<string> &blocks) {
    rep(y,h) {
        rep(x,w) {
            cout<<blocks[y][x];
        }
        cout<<endl;
    }
    cout<<endl;
}
bool erase(vector<string> &blocks) {
    bool res=false;
    bool flag[31][31]={};
    rep(y,h) rep(x,w) {
        char c=blocks[y][x];
        if(c=='.') c='+';
        int ny=y;
        while(ny<h&&c==blocks[ny][x]) {
            ny++;
        }
        if(n<=ny-y) {
            for(int i=y;i<ny;i++) flag[i][x]=true;
        }
        int nx=x;
        while(nx<w&&c==blocks[y][nx]) {
            nx++;
        }
        if(n<=nx-x) {
            for(int i=x;i<nx;i++) flag[y][i]=true;
        }
    }

    rep(y,h) rep(x,w) if(flag[y][x]) blocks[y][x]='.';
    rep(y,h) rep(x,w) if(flag[y][x]) res=true;
    return res;
}
void fall(vector<string> &blocks) {
    for(int y=h-1;y>=0;y--) rep(x,w) {
        if(blocks[y][x]!='.') {
            int tmp=y;
            while((tmp+1)<h && blocks[tmp+1][x]=='.') {
                blocks[tmp+1][x] = blocks[tmp][x];
                blocks[tmp][x]='.';
                tmp++;
            }
        }
    }
}
bool ok(vector<string> blocks) {
    fall(blocks);
    while(erase(blocks)) {
        // dump(blocks);
        fall(blocks);
    }

    bool res=true;
    rep(y,h) rep(x,w) res&=blocks[y][x]=='.';
    return res;
}
int main() {
    vector<string> blocks(31);
    cin>>h>>w>>n;
    rep(i,h) cin>>blocks[i];
    rep(y,h) {
        rep(x,w-1) {
            swap(blocks[y][x],blocks[y][x+1]);
            // printf("[debug] %d %d %d\n", y,x,x+1);
            if(ok(blocks)) {
                cout<<"YES"<<endl;
                return 0;
            }
            swap(blocks[y][x],blocks[y][x+1]);
        }
    }
    cout<<"NO"<<endl;

    return 0;
}

