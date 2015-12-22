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

int H,W;
string maze[10];
template<class T>
bool chmin(T &a, const T &b) {
    if(a>b) {
        a=b;
        return true;
    }
    return false;
}

int dp[11][11];
void bfs(const vector<P> &city,const vector<P> &source) {
    int S=0;
    rep(y,11) rep(x,11) dp[y][x]=INF;
    queue<P> que;
    rep(i,source.size()) {
        P p=source[i];
        dp[p.fr][p.sc]=0;
        que.push(p);
    }

    while(que.size()) {
        P p=que.front(); que.pop();
        int pos=find(all(city),p)-city.begin();
        if(pos!=city.size()) {
            S=S|1<<pos;
        }
        if(S+1==(1<<city.size())) break;
        rep(k,4) {
            int ny=p.fr+dy[k];
            int nx=p.sc+dx[k];
            if(!(0<=ny&&ny<H)) continue;
            if(!(0<=nx&&nx<W)) continue;
            if(dp[ny][nx]!=INF) continue;
            dp[ny][nx]=dp[p.fr][p.sc]+1;
            que.push(P(ny,nx));
        }
    }
}
int func(const vector<P> &city, const vector<P> &source) {
    set<P> s;
    rep(i,city.size()) {
        P p=city[i];
        int cost=dp[p.fr][p.sc];
        s.insert(p);
        printf("(%d, %d)-> ",p.fr,p.sc);
        while(cost) {
            rep(k,4) {
                int ny=p.fr+dy[3-k];
                int nx=p.sc+dx[3-k];
                if(!(0<=ny&&ny<H)) continue;
                if(!(0<=nx&&nx<W)) continue;
                if(cost-1==dp[ny][nx]) {
                    cost--;
                    p=P(ny,nx);
                    s.insert(p);
                    printf("(%d, %d)-> ",p.fr,p.sc);
                }
            }
        }
        cout<<endl;
    }

    for(auto e : s) {
        cout<<e.fr<<", "<<e.sc<<endl;
    }
    cout<<s.size()<<endl;
    return 0;
}

void solve() {
    vector<P> source;
    vector<P> city;
    rep(i,H) cin>>maze[i];
    rep(y,H) rep(x,W) {
        if(maze[y][x]=='P') source.pb(mp(y,x));
        else if(maze[y][x]=='*') city.pb(mp(y,x));
    }
    bfs(city,source);
    func(city,source);
}

int main() {
    while(cin>>H>>W) {
        if(H==0) break;
        solve();
    }
    return 0;
}

