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

int N;
int ans;
vector<int> vec[100005];
int solve(vector<int> &A) {
    int ret=1;
    rep(i,N) {
        vec[A[i]].pb(i);
    }
    set<int> S;
    rep(i,N) S.insert(A[i]);
    for(auto e:S) sort(all(vec[e]));

    int idx=0;

    rep(i,100005) if(S.count(i)) {
        auto it=lower_bound(all(vec[i]),idx);
        if(it==vec[i].begin()) idx=vec[i].back();
        else {
            it--;
            idx=*it;
            ret++;
        }
    }

    if(idx==0) ret--;

    //cout<<"ret = "<<ret<<endl;
    return ret;
}
int main() {
    cin>>N;
    vector<int> A(N);
    rep(i,N) cin>>A[i];
    ans=solve(A);
    cout<<ans<<endl;
    return 0;
}

