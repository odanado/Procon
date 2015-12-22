#include<algorithm>
#include<functional>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<climits>

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define FOR(itr,data) for(__typeof((data).begin()) itr=(data).begin();itr!=(data).end();++itr)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

typedef unsigned long long UInt64;
typedef long long Int64;

const int INF=100000000;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

using namespace std;

typedef pair<int ,int > P;

class LCMSetEasy {
public:
   string include(vector <int> S, int x) {
       vector<int> vec1,vec2;
       rep(i,S.size()) {
           for(int j=2;j*j<=S[i];j++) {
               if(S[i]%j==0) vec1.pb(j);
           }
       }
       sort(all(vec1));
       for(int i=2;i*i<=x;i++) {
           vec2.pb(i);
       }
       rep(i,vec1.size()) {
           if(x%vec1[i]==0) {
               x/=vec1[i];
           }
       }
       return i==1?"Possible":"Impossible";

   } 

};

int main() {
    return 0;
}



