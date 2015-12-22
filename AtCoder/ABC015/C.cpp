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

int N,K;
int T[6][6];
string ans="Nothing";
void dfs(int i,int s) {
    if(i==N) {
        if(s==0) ans="Found";
        return;
    }
    rep(j,K) dfs(i+1,s^T[i][j]);
}
int main() {
    cin>>N>>K;
    rep(i,N) rep(j,K) cin>>T[i][j];
    dfs(0,0);
    cout<<ans<<endl;
    return 0;
}

