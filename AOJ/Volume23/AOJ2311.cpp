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
typedef vector<string> Board;

bool reverse_rec(Board& board, char stone,int x,int y, int dx,int dy) {
    if(x>7 || y>7) return false;
    if(x<0 || y<0) return false;
    if(board[y][x]=='.') return false;
    if(board[y][x]==stone) return true;

    bool flag = reverse_rec(board, stone, x+dx,y+dy,dx,dy);

    if(flag) {
        board[y][x]=stone;
    }
        
    return flag;
}
int count(Board& board, char stone) {
    int res=0;
    rep(i,board.size()) rep(j,board[i].size()) if(board[i][j]==stone) res++;
    return res;
}
void plot(Board& board) {
    rep(i,board.size()) {
        rep(j,board[i].size()) {
            cout<<board[i][j];
        }
        cout<<endl;
    }

}
void reverse(Board &board, char stone, int x, int y) {
    if(board[y][x]!='.') return;
    for(int dx=-1;dx<=1;dx++) {
        for(int dy=-1;dy<=1;dy++) {
            if(!(0<=x+dx&&x+dx<8)) continue;
            if(!(0<=y+dy&&y+dy<8)) continue;
            // cout<<dx<<","<<dy<<endl;

            if(board[dy+y][dx+x]!=stone && reverse_rec(board,stone,x+dx,y+dy,dx,dy)) {
                board[y][x]=stone;

            }
        }
    }

}

bool mami(Board &board) {
    int maxi = count(board, 'o');
    bool flag = false;
    Board res = board;
    rep(i,8) {
        rep(j,8) {
            Board tmp = board;
            reverse(tmp, 'o', j, i);
            if(maxi < count(tmp,'o')) {
                maxi = count(tmp,'o');
                res = tmp;
                flag = true;

            }
        }
    }
    board = res;
    return flag;
}
bool majo(Board &board) {
    int maxi = count(board, 'x');
    bool flag = false;
    Board res = board;
    for(int i=7;i>=0;i--) {
        for(int j=7;j>=0;j--) {
            Board tmp = board;
            reverse(tmp, 'x', j, i);
            if(maxi < count(tmp,'x')) {
                maxi = count(tmp,'x');
                res = tmp;
                flag = true;
            }
        }
    }
    board = res;
    return flag;
}

int main() {
    Board board;
    rep(i,8) {
        string str;
        cin>>str;
        board.pb(str);
    }

    while(1) {
        bool f = mami(board);
        f |= majo(board);
        if(!f) {
            plot(board);
            break;
        }

    }
    return 0;
}

