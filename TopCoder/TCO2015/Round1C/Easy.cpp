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

class DevuAndPlantingTrees {
public:
    bool ok(const vector<string>& garden, int y,int x) {
        bool ret=true;
        for(int dy=-1;dy<=1;dy++) for(int dx=-1;dx<=1;dx++) {
            int ny=y+dy;
            int nx=x+dx;
            if(!(0<=ny&&ny<garden.size())) continue;
            if(!(0<=nx&&nx<garden[0].size())) continue;
            ret &= garden[y][x]=='.';
        }

        return ret;
    }
    int maximumTreesDevuCanGrow(vector <string> garden) {
        rep(y,garden.size()) rep(x,garden[y].size()) {
            if(ok(garden,y,x)) garden[y][x]='*';
        }
        int ans=0;
        rep(y,garden.size()) rep(x,garden[y].size()) {
            if(garden[y][x]=='*') ans++;
        }

        return ans;
    }
};

int main() {
    return 0;
}

