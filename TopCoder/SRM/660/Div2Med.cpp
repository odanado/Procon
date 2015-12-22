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

class PrivateD2party{
public:
    bool visited[51]={};
    vector<int> G,rev[51];
    int f(int u) {
        visited[u]=true;
        if(!visited[G[u]]) {
            return f(G[u])+1;
        }

        return 0;
    }
    int root(int u,int v) {
        rep(i,rev[v].size()) {
            if(u==rev[v][i]) continue;
            return root(v,rev[v][i]);
        }

        return v;
    }
    int getsz(vector <int> a) {
        G=a;
        rev.resize(a.size());
        rep(i,a.size()) {
            rev[a[i]].pb(i);
        }
        int ans=0;
        rep(i,a.size()) {
            printf("%d %d\n",a[i],root(a[i]));
            ans+=f(root(a[i]));
        }

        return ans;
    }
};

int main() {
    return 0;
}

