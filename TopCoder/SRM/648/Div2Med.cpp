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

class Fragile2 {
public:
    int bfs(const vector<string>& g) {
        vector<string> g2 = g;
        int cnt = 0;
        rep(i,g2.size()) {
            rep(j,g2[i].size()) {
                if(g2[i][j]=='Y') {
                    cnt++;
                    queue<int> que;
                    que.push(i);
                    while(que.size()) {
                        int t = que.front(); que.pop();
                        rep(k,g2[t].size()) {
                            if(g2[t][k]=='Y') {
                                que.push(k);
                                g2[t][k]='N';
                                g2[k][t]='N';
                            }
                        }
                    }
                }
            }
        }
        
        return cnt;
    }
    void remove(vector<string>& g, int v) {
        rep(i,g[v].size()) g[v][i]=g[i][v]='N';
    }
    int countPairs(vector <string> g) {
        rep(i,g.size()) g[i][i]='Y';
        int cnt = bfs(g);
        int ans = 0;
        cout<<cnt<<endl;
        rep(i,g.size()) rep(j,g[i].size()) {
            if(i <= j) continue;
            vector<string> t = g;
            remove(g,i);
            remove(g,j);

            if(cnt < bfs(g)) {
                cout<<bfs(g)<<","<<i<<","<<j<<endl;
                ans++;
            }


            g = t;
        }

        return ans;
    }

};

int main() {
    return 0;
}

