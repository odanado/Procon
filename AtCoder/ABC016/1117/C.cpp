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

vector<int> G[10];

int bfs(int s) {
    queue<int> que1,que2;
    que1.push(s);
    que2.push(0);
    int cnt=0;

    while(!que1.empty()) {
        int v=que1.front(); que1.pop();
        int dist=que2.front();que2.pop();
        if(dist==2) {
            if(v!=s) cnt++;
            continue;
        }
        for(int i=0;i<G[v].size();i++) {
            int next=G[v][i];
            if(v==next) continue;
            que1.push(next);
            que2.push(dist+1);
        }
    }

    return cnt;
}

int main() {
    int N,M;
    cin>>N>>M;
    rep(i,M) {
        int v,u;
        cin>>v>>u;
        v--,u--;
        G[v].push_back(u);
        G[u].push_back(v);
    }
    rep(i,N) {
        cout<<bfs(i)<<endl;
    }
    return 0;
}

