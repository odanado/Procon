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

vector<pair<int,P> > circle;
bool ok(int r2,int x2,int y2) {
    rep(i,circle.size()) {
        int r3 = circle[i].fr;
        int x3 = circle[i].sc.fr;
        int y3 = circle[i].sc.sc;
        if((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3) <= (r2+r3)*(r2+r3)) {
            return false;
        }
    }

    return true;

}
int main() {
    rep(i,100) {
        for(int x=i+1;x<1500-i-1;x++) {
            for(int y=i+1;y<1500-i-1;y++) {
                if(ok(i+1,x,y)) {
                    pair<int,P> pi = pair<int,P>(i+1,P(x,y));
                    circle.pb(pi);
                    // cout<<"r = "<<i+1<<endl;
                    goto go;
                }
            }
        }
go:;
    }
    rep(i,circle.size()) {
        int x3 = circle[i].sc.fr;
        int y3 = circle[i].sc.sc;
        cout<<x3<<" "<<y3<<endl;

    }
    return 0;
}

