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
typedef long long ll;

int N,a,b;
int K;
set<int> P;
int main() {
    bool ok=true;
    cin>>N>>a>>b;
    P.insert(a);
    P.insert(b);
    cin>>K;
    rep(i,K) {
        int c;cin>>c;
        if(P.count(c)) ok=false;
        P.insert(c);
    }
    if(ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}

