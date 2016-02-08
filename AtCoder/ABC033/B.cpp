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

int N;
string S[1003];
int P[1003];
int main() {
    int N;
    cin>>N;
    rep(i,N) cin>>S[i]>>P[i];
    int s=0;
    rep(i,N) s+=P[i];
    string ans="atcoder";
    rep(i,N) if(s/2<P[i]) ans=S[i];
    cout<<ans<<endl;
    return 0;
}

