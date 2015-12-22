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

char trump;
vector<string> card[4];
int rank['Z'];

void solve() {
    int ew=0,ns=0;
    rep(i,4) card[i].clear();
    rep(i,4) card[i].resize(13);
    rep(i,4) rep(j,13) cin>>card[i][j];
    int parent=0;

    rep(i,13) {
        int win=0,maxi=0;
        bool f=false;
        char led=card[parent][i][1];
        rep(j,4) {
            int r=rank[card[j][i][0]];
            char s=card[j][i][1];
            if(f) {
                if(s==trump && maxi<r) {
                    maxi=r;
                    win=j;
                }
            }
            else {
                if(s==trump) {
                    f=true;
                    maxi=r;
                    win=j;
                }
                else if(s==led && maxi<r) {
                    maxi=r;
                    win=j;
                }
            }
        }
        parent=win;
        if(win%2==0) ns++;
        else ew++;
    }
    if(ns<ew) {
        cout<<"EW "<<ew-6<<endl;
    }
    else {
        cout<<"NS "<<ns-6<<endl;
    }


}

int main() {
    rep(i,10) rank[i+'0']=i;
    rank['T']=10;
    rank['J']=11;
    rank['Q']=12;
    rank['K']=13;
    rank['A']=14;
    while(cin>>trump) {
        if(trump == '#') break;
        solve();
    }
    return 0;
}

