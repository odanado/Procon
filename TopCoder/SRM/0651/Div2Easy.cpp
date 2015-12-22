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

class RobotOnMoonEasy {
public:
    P func(vector<string> &board) {
        rep(y,board.size()) rep(x,board[y].size()) if(board[y][x]=='S') return P(y,x);

    }
    string isSafeCommand(vector <string> board, string S) {
        P s=func(board);
        int x=s.fr;
        int y=s.sc;
        rep(i,S.size()) {
            int dx=0,dy=0;
            char c = S[i];
            if(c=='U') dy=-1;
            if(c=='D') dy=1;
            if(c=='R') dx=1;
            if(c=='L') dx=-1;
            int ny=y+dy;
            int nx=x+dx;
            printf("%d %d\n",ny,nx);
            if(!(0<=ny&&ny<board.size())) return "Dead";
            if(!(0<=nx&&nx<board[ny].size())) return "Dead";
            if(board[ny][nx]=='#') ny=y,nx=x;
            else y=ny,x=nx;
        }
        return "Alive";


    }
};
