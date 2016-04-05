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
vector<int> amida;
void print(const vector<int> &vec) {
    for(auto e:vec) cout<<e<<" ";
    cout<<endl;
}
vector<int> mul(const vector<int> &vec1, const vector<int> &vec2) {
    vector<int> vec(vec1.size());

    rep(i,vec1.size()) {
        vec[i]=vec1[vec2[i]];
    }

    return vec;
}
vector<int> power(vector<int> vec,int n) {
    vector<int> ret(vec.size());
    rep(i,ret.size()) ret[i]=i;

    while(n) {
        if(n&1) ret=mul(ret,vec);
        vec=mul(vec,vec);
        n>>=1;
    }
    return ret;
}
int main() {
    cin>>N>>M>>D;
    rep(i,M) cin>>A[i];
    amida.resize(max(M,N)+1);
    rep(i,amida.size()) amida[i]=i;

    rep(i,M) swap(amida[A[i]-1],amida[A[i]]);
    amida=power(amida, D);
    vector<int> ans;
    ans.resize(N);
    rep(i,N) {
        ans[amida[i]]=i+1;
    }
    rep(i,N) cout<<ans[i]<<endl;

    return 0;
}

