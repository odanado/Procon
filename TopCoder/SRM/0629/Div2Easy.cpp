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

class RectangleCoveringEasy {
public:
    bool f(int holeH, int holeW, int boardH, int boardW) {
        if(holeH == boardH) {
            if(boardW-holeW>=1) return true;
            else return false;
        }
        else if(holeH<boardH) {
            return holeW<boardW;
        }
        return false;
    }
    int solve(int holeH, int holeW, int boardH, int boardW) {
        bool ret = false;
        ret |= f(holeH,holeW,boardH,boardW);
        ret |= f(holeW,holeH,boardH,boardW);
        
        if(ret) return 1;
        else return -1;

    }
};

int main() {
    return 0;
}

