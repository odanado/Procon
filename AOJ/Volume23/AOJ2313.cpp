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

struct Edge { 
    int to,cap,rev,flow; 
    Edge(int to=0,int cap=0,int rev=0) :
        to(to),cap(cap),rev(rev){}
};

int N,E,Q;

vector<Edge> G[505];
int main() {
    cin>>N>>E>>Q;
    rep(i,E) {
        int a,b;
        cin>>a>>b;
        G[a].pb(Edge(b,1,G[b].size()));
        G[b].pb(Edge(a,0,G[a].size()-1));
    }

    while(Q-->0) {
        int m,a,b;
        cin>>m>>a>>b;
    }
    return 0;
}

