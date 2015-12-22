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

int S[103],T[103];
int N,D,K;
int L[10004],R[10004];
bool contain(int s1,int t1,int s2,int t2) {
    if(t1<s2||t2<s1) return false;
    return true;
}
int solve(int s,int t) {
    int l,r;
    l=r=s;
    rep(i,D) {
        if(contain(l,r,L[i],R[i])) {
            l=min(l,L[i]);
            r=max(r,R[i]);
        }
        //printf("[debug] %d : %d %d\n",i,l,r);
        if(l<=t&&t<=r) return i;
    }

    return INF;
}
int main() {
    cin>>N>>D>>K;
    rep(i,D) cin>>L[i]>>R[i];
    rep(i,K) cin>>S[i]>>T[i];
    rep(i,K) cout<<solve(S[i],T[i])+1<<endl;
    return 0;
}

