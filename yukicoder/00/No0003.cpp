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

int N;

int popcount(int n) {
    int ret = 0;
    while(n) {
        if(n&1) ret++;
        n>>=1;
    }
    return ret;
}

int d[10004];
int bfs() {
    rep(i,10004) d[i]=INF;
    d[1] = 1;
    queue<int> que;
    que.push(1);
    while(que.size()) {
        int p=que.front(); que.pop();
        int t=popcount(p);

        if(p+t<=N&&d[p+t]>d[p]+1) {
            d[p+t]=d[p]+1;
            que.push(p+t);
        }
        if(p-t>0&&d[p-t]>d[p]+1) {
            d[p-t]=d[p]+1;
            que.push(p-t);
        }
    }
    int ret=d[N];
    if(ret==INF) return -1;
    else return ret;
}

int main() {
    cin>>N;
    cout<<bfs()<<endl;
    return 0;
}

