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

class UnrelatedPaths {
public:
    vector<int> G[60];
    int maxUnrelatedPaths(vector <int> parent) {
        rep(i,parent.size()) {
            G[i+1].pb(parent[i]);
            G[parent[i]].pb(i+1);
        }
        int ans=0;
        rep(i,60) if(G[i].size()==1) ans++;
        return ans;
    }
};

int main() {
    return 0;
}

