#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
#include <cstdint>
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
int dx[4]={1,1,-1,-1};
int dy[4]={1,-1,1,-1};
using namespace std;
typedef pair<int ,int > P;
typedef pair<P,P> PP;

class BishopMove {
public:
    int dist[10][10];
    int howManyMoves(int r1, int c1, int r2, int c2) {
        rep(i,10) rep(j,10) dist[i][j]=INF;
        dist[r1][c1] = 0;
        queue<PP> que;
        que.push(PP(P(r1,c1),P(2,2)));
        int ans = -1;

        while(que.size()) {
            PP p = que.front();
            que.pop();
            if(p.first.fr == r2 && p.fr.second == c2) {
                ans = dist[r2][c2];
                break;
            }
            rep(i,4) rep(j,4) {
                int r = p.fr.first + dx[i];
                int c = p.fr.second + dy[j];
                int cost = 1;
                if(!(0<=r&&r<8)) continue;
                if(!(0<=c&&c<8)) continue;
                if(dx[i]==p.sc.fr&&dy[j]==p.sc.sc) cost = 0;
                if(dist[r][c] < dist[p.fr.fr][p.fr.sc]+cost) continue;

                dist[r][c] = dist[p.fr.fr][p.fr.sc] + cost;
                que.push(PP(P(r,c),P(dx[i],dy[j])));
            }
        }
        return ans;

    }

};

int main() {
    return 0;
}

