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
int B[100005];
P in[100005];
int main() {
    cin>>N>>T;
    rep(i,N) cin>>A[i]>>B[i];
    rep(i,N) in[i]=P(A[i]-B[i],i);

    ll sum=0;
    ll ans=N;
    sort(in,in+N);
    rep(i,N) sum+=B[i];
    if(sum>T) {
        cout<<"-1"<<endl;
        return 0;
    }

    rep(i,N) {
        int idx=in[i].sc;
        if(sum+in[i].fr>T) break;
        ans--;
        sum+=in[i].fr;
    }
    cout<<ans<<endl;



    return 0;
}

