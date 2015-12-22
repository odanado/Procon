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

class BichromeBoard {
public:
    bool ok(const vector<string> &b,char c) {
        rep(i,b.size()) rep(j,b[i].size()) {
            if(b[i][j]==c) {
                rep(y,b.size()) rep(x,b[y].size()) if(!((i%2==y%2)^(j%2==x%2))) if(c!=b[y][x]) return false;
            }
        }
        return true;
    }
    string ableToDraw(vector <string> board) {
        if(ok(board,'B')&&ok(board,'W')) return "Possible";
        else return "Impossible";
    }
};

int main() {
    return 0;
}

