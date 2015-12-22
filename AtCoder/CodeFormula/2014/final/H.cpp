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

int N,S1,S2;
int A[50003];
int B[50003];

int main() {
    cin>>N>>S1>>S2;
    rep(i,N) cin>>A[i]>>B[i];
    int ans = 0;
    rep(i,N) rep(j,N) {
        if(i==j) continue;
        int t = (A[i]-A[j])*(B[i]-B[j]);
        if(S1<= t && t<=S2) ans++;
    }
    cout<<ans/2<<endl;
    return 0;
}

