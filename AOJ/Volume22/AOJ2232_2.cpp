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
vector<string> block;
bool del[33][33];
void init() {
    rep(i,33) rep(j,33) del[i][j]=false;
}

void print() {
    rep(i,h) cout<<block[i]<<endl;
    cout<<endl;
}

void fall() {
    rep(i,h) {
    for(int y=h-1;y>0;y--) {
        rep(x,w) {
            if(block[y][x]=='.') {
                swap(block[y][x],block[y-1][x]);
            }
        }
    }
    }
}
bool ok() {
    bool res = true;
    rep(y,h) rep(x,w) {
        res &= block[y][x]=='.';
    }
    return res;
}

void func(int y,int x,int d) {
    int cnt=1;
    char c=block[y][x];

    while(1) {
        if(!(0<=x&&x<w)) return;
        if(!(0<=y&&y<h)) return;
        if(c!=block[y][x]) return;
        if(cnt==n) {
            int nx=x;
            int ny=y;
            rep(i,n) {
                del[ny][nx]=true;
                ny-=dy[d];
                nx-=dx[d];
            }            
        }
        if(cnt > n) del[y][x]=true;
        cnt++;
        y+=dy[d];
        x+=dx[d];
    }

}

void exec() {
    init();
    rep(y,h) rep(x,w) {
        func(y,x,0);
        func(y,x,1);
        fall();
    }
    rep(y,h) rep(x,w) if(del[y][x]) block[y][x]='.';

}


int main() {
    cin>>h>>w>>n;
    block.resize(h);
    rep(i,h) cin>>block[i];

    bool ans = false;
    rep(y,h) rep(x,w-1) {
        vector<string> tmp = block;
        swap(block[y][x],block[y][x+1]);

        exec();
        print();
        ans |= ok();
        block = tmp;
    }
    if(ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}

