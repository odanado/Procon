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

int n,m;
int bfs(int a) {
    int d[10004];
    rep(i,10004) d[i]=INF;
    d[a]=0;
    queue<int> que;
    que.push(a);
    while(que.size()) {
        int t=que.front();
        que.pop();

        if(t==m) return d[t];
        if(t-1>=0 && d[t-1]==INF) {
            d[t-1]=d[t]+1;
            que.push(t-1);
        }
        if(t*2<10004 && d[t*2]==INF) {
            d[t*2]=d[t]+1;
            que.push(t*2);
        }
    }

    return INF;
}
int main() {
    cin>>n>>m;
    cout<<bfs(n)<<endl;
    return 0;
}

