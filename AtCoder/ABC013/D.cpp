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

int N,M,D;
int A[200005];
int amida[200005];
int main() {
    cin>>N>>M>>D;
    rep(i,M) cin>>A[i];
    rep(i,200005) amida[i]=i;
    rep(i,M) swap(amida[A[i]-1],amida[A[i]]);

    int cnt = 0;
    rep(i,N) if(amida[i]==i) cnt++;
    D = D % (N-cnt);
    rep(i,D-1) rep(i,M) swap(amida[A[i]-1],amida[A[i]]);
    vector<int> ans;
    ans.resize(N);
    rep(i,N) {
        ans[amida[i]]=i+1;
    }
    rep(i,N) cout<<ans[i]<<endl;

    return 0;
}

