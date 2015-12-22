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

int n;
bool grid[1003][1003];
void solve() {
    rep(i,1003) rep(j,1003) grid[i][j]=false;
    int dx,dy;
    int x=0,y=0;
    while(1) {
        cin>>dx>>dy;
        if(dx==0&&dy==0) break;
        x+=dx;
        y+=dy;
        grid[y][x]=true;
    }
    int maxi=0;
    P ans;

    rep(i,1003) rep(j,1003) {
        if(grid[i][j]) {
            if(maxi < i*i + j*j) {
                maxi = i*i + j*j;
                ans=P(j,i);
            }
        }
    }
    cout<<ans.fr<<" "<<ans.sc<<endl;

}
int main() {
    cin>>n;
    rep(i,n) solve();
    return 0;
}

