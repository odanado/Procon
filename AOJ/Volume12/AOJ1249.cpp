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


int dx[] = { 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1};
int dy[] = { 0, 1, 0, 1,-1, 0, 0, 1, 1, 1, 1,-1,-1};
int dz[] = { 0, 0, 1, 0, 0, 1,-1, 1,-1, 1,-1, 1,-1};


using namespace std;
typedef pair<int ,int > P;
typedef long long ll;

int n,m,p;

int a[8][8][8];

void put(int x, int y, int c) {
    rep(i,n) {
        if(a[x][y][i]==0) {
            a[x][y][i]=c;
            break;
        }
    }
}

bool win(int c) {
    rep(x,n) rep(y,n) rep(z,n) {
        int t=a[x][y][z];
        if(t!=c) continue;
        rep(i,13) {
            bool f=true;
            int nx = x;
            int ny = y;
            int nz = z;
            rep(j,m) {
                if(!(0<=nx&&nx<n)) {
                    f=false;
                    break;
                }
                if(!(0<=ny&&ny<n)) { 
                    f=false;
                    break;
                }
                if(!(0<=nz&&nz<n)) {
                    f=false;
                    break;
                }
                f &= c==a[nx][ny][nz];
                nx+=dx[i];
                ny+=dy[i];
                nz+=dz[i];
            }

            if(f) return true;
        }
    }

    return false;
}

void solve() {
    rep(i,8) rep(j,8) rep(k,8) a[i][j][k]=0;
    int c = 1;
    bool flag=false;
    rep(i,p) {
        int x,y;
        cin>>x>>y;
        x--,y--;
        put(x,y,c);
        if(flag) continue;
        if(win(c)) {
            printf("%s %d\n", (i+1)&1?"Black":"White", i+1);

            // printf("x,y = %d %d\n",x,y);
            flag=true;
        }
        if(c==1) c=2;
        else c=1;
    }
    if(!flag)
        cout<<"Draw"<<endl;
    /*
    cout<<endl;
    rep(i,8) rep(j,8) {
        cout<<i<<" "<<j<<" : ";
        rep(k,8) {
            cout<<a[i][j][k]<<" ";
        }
        cout<<endl;

    }
    */

}

int main() {
    while(cin>>n>>m>>p) {
        if(n+m+p==0) break;
        solve();
    }
    return 0;
}

