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
typedef pair<P,int> Pi;
typedef long long ll;

int n,k;
vector<Pi > vec;
int maxi[1000000];
int ary[1000000];
bool f[1000000];
int user[60][1003];
int cnt;
int cnt2;
void func() {
  int t = ceil(1.0*(k-cnt)/(n-cnt2));
  //cout<<(k-cnt)<<","<<(n-cnt2)<<endl;
  cout<<t<<endl;
  cnt2++;
  //int t = min(k-cnt,(k/n)+1);
  rep(i,1000000) {
    P p = P(maxi[i],ary[i]);
    Pi pi = Pi(p,i);
    if(i&&!f[i]&&maxi[i]!=INF) {
      f[i]=true;
      vec.pb(pi);
    }
  }
  sort(all(vec));

  vector<int> ans;
  rep(j,vec.size()) if(vec[j].fr.fr < t) ans.pb(vec[j].sc);
  sort(all(ans));
  rep(j,ans.size()) cout<<ans[j]<<" ";

  //rep(j,vec.size()) cout<<vec[j].fr.fr<<","<<vec[j].fr.sc<<","<<vec[j].sc<<endl;
  vec.erase(vec.begin(),vec.begin()+(t));

  cout<<endl;
  cnt+=ans.size();

}
int main() {
  cin>>n>>k;
  rep(i,1000000) maxi[i] = INF;


  rep(i,n) {
    rep(j,k) {
      int a;
      cin>>a;
      user[i][j]=a;
      if(j < maxi[a]) {
        maxi[a] = j;
        ary[a] = i;
      }
    }
    func();
  }


    return 0;
  }

