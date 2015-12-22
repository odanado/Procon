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

int N,T;
int A[100005];
int main() {
    cin>>N>>T;
    rep(i,N) cin>>A[i];
    ll ans=0;
    int p=A[0]+T;
    ans=T;
    rep(i,N) if(i) {
        if(A[i]<=p) {
            ans+=A[i]+T-p;
            p=A[i]+T;
        }
        else {
            ans+=T;
            p=A[i]+T;
        }
    }
    cout<<ans<<endl;
    return 0;
}

