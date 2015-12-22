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

int n,k;
int user[60][1003];
bool f[1000000];
int main() {
  cin>>n>>k;
  rep(i,n) rep(j,k) cin>>user[i][j];

  rep(i,n) {
    vector<int> ans;
    int t = k/n + 1;
    int t2 = t;
    while(t --> 0) {
      int j = t2-t-1;
      if(!f[user[i][j]]) {
        ans.pb(user[i][j]);
        f[user[i][j]]=true;
      }
    }
    sort(all(ans));
    rep(i,ans.size()) cout<<ans[i]<<" ";
    cout<<endl;
  }

    return 0;
}

