#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

int m;
int p[5][5];
bool ok(int y1,int x1,int y2,int x2) {
    for(int y=y1;y<=y2;y++) {
        for(int x=x1;x<=x2;x++) {
            if(p[y][x]==0) return 0;
        }
    }
    return 1;
}
int solve() {
    int res = 0;
    rep(y1,5) rep(x1,5) {
        rep(y2,5) rep(x2,5) {
            if(!(y1<=y2 && x1<=x2)) continue;
            if(ok(y1,x1,y2,x2)) {
                //printf("debug: %d %d %d %d\n",y1,x1,y2,x2);
                res = max(res, (y2-y1+1)*(x2-x1+1));
            }
        }
    }
    return res;
}
int main() {
    cin>>m;
    rep(_,m) {
        rep(i,5) rep(j,5) cin>>p[i][j];
        cout << solve() << endl;
    }
}
