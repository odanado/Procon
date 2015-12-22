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

int N,M;
int A[20];
int B[51];
int C[51];
int I[51][51];
int bitcount(int S) {
    int res=0;
    while(S) {
        if(S&1) res++;
        S>>=1;
    }
    return res;
}
int sumA(int S) {
    int res=0;
    rep(i,16) {
        if((S>>i)&1) res+=A[i];
    }
    return res;
}
bool combo_ok(int i,int S) {
    int cnt=0;
    rep(j,C[i]) {
        if((S>>I[i][j])&1) cnt++;
    }

    return cnt>=3;
}
int main() {
    cin>>N>>M;
    rep(i,N) cin>>A[i];
    rep(i,M) {
        cin>>B[i]>>C[i];
        rep(j,C[i]) {
            cin>>I[i][j];
            I[i][j]--;
        }
    }
    int ans = 0;

    rep(S,1<<16) {
        if(bitcount(S) != 9) continue;
        int sum=0;
        sum = sumA(S);
        rep(i,M) {
            if(combo_ok(i,S)) {
                sum += B[i];
            }
        }
        ans=max(ans,sum);
    }

    cout<<ans<<endl;
    return 0;
}

